from selenium import webdriver#该脚本运用selenium库实现自动化操作浏览器
from selenium.webdriver.support.ui import WebDriverWait#用于等待网页完全加载
from selenium.webdriver.support import expected_conditions as EC# 用于等待元素加载
from selenium.webdriver.common.keys import Keys#用于模拟键盘操作
from selenium.webdriver.common.by import By 
import getpass#用于隐藏密码输入，getpass库可以在命令行中隐藏用户输入的密码，提升安全性
import time#设置操作间等待时长
from selenium.webdriver.common.action_chains import ActionChains#JS动作链
from selenium.webdriver.edge.options import Options#用于配置Edge浏览器选项使网页不再在脚本运行结束后自动关闭
edge_options = Options()
edge_options.add_experimental_option("detach", True)
edge_options.add_argument("--ignore-certificate-errors")
edge_options.add_argument("--allow-insecure-localhost")
edge_options.add_argument("--disable-features=SegmentationPlatform,OptimizationGuideModelFetching")
edge_options.add_argument("--disable-gpu")
edge_options.add_argument("--no-sandbox")
edge_options.add_argument("--disable-dev-shm-usage")
edge_options.add_experimental_option("excludeSwitches", ["enable-logging"])

driver = webdriver.Edge(options=edge_options)#启动Edge浏览器

driver.execute_cdp_cmd("Page.addScriptToEvaluateOnNewDocument", {
    "source": """
        Object.defineProperty(navigator, 'webdriver', {
            get: () => undefined
        })
    """
})#防止被检测出使用了自动化工具

print("脚本启动成功！")
print("使用须知：若发现无法进入网页，请先检查并关闭代理服务器，路径：系统--网络与Int--关闭代理服务器")
print("输入你的账号（学号）")
account = input()
driver.maximize_window() #最大化窗口   
driver.get("http://www.gaoxiaokaoshi.com/Loginb.aspx")
username_input = WebDriverWait(driver, 10).until(
    EC.presence_of_element_located((By.NAME, "name"))
)
username_input.send_keys(account)
print("接下来输入密码（默认六个零，已隐藏输入）")
key = getpass.getpass()
username_input = WebDriverWait(driver, 10).until(
    EC.presence_of_element_located((By.NAME, "pw"))
)
username_input.send_keys(key)

try:
    login_button = WebDriverWait(driver, 10).until(
    EC.element_to_be_clickable((By.ID, "btnSubmit"))
)
except Exception as e:
    print("找不到登录按钮:", e)
login_button.click()
print("登录中，请稍后...")

time.sleep(0.5)
#用js打开新标签页
original_url = driver.current_url
original_window = driver.current_window_handle
all_tabs = [original_window]
for i in range(36):#9*4=36
    driver.execute_script("window.open(arguments[0], '_blank');", original_url)
    WebDriverWait(driver, 10).until(EC.number_of_windows_to_be(len(all_tabs) + 1))

    all_tabs = driver.window_handles
    new_tab = all_tabs[-1]
    driver.switch_to.window(new_tab)
    print("已打开新标签页：", driver.current_url)

    iframe = WebDriverWait(driver, 15).until(
    EC.presence_of_element_located((By.ID, "mainIframe"))#切换为实际 iframe 的 id
    )
    driver.switch_to.frame(iframe)
    print("已切换到 iframe")


    try:
        j = 0
        w = i//9#每页有9个视频

        for j in range(w):
            next_btn = WebDriverWait(driver, 10).until(
            EC.element_to_be_clickable((By.XPATH, '//*[@id="PageSplit1_BtnNext"]'))
            )
            next_btn.click()
            time.sleep(1)
        
        target_element = WebDriverWait(driver, 10).until(
        EC.element_to_be_clickable((By.XPATH, f'//*[@id="form1"]/div[4]/table/tbody/tr[{2 + i%9}]/td[6]/a'))
        )
        print("成功捕获元素，文本内容：", target_element.text)
        driver.execute_script("arguments[0].scrollIntoView();", target_element)
        target_element.click()


        driver.switch_to.default_content()#同级iframe间切换得先切回主文档
        frame = WebDriverWait(driver, 15).until(
        EC.presence_of_element_located((By.ID, "ExamView"))#切换为播放键所在iframe id
        )
        driver.switch_to.frame(frame)
        print("已切换到视频 iframe")

        time.sleep(2)
        play_container = WebDriverWait(driver, 15).until(
            EC.presence_of_element_located((By.CLASS_NAME, 'prism-big-play-btn'))
        )
        play_button = play_container.find_element(By.CLASS_NAME, "outter")
        # 模拟鼠标悬停后点击（应对hover动画）
        ActionChains(driver).move_to_element(play_button).click().perform()
        print("点击播放按钮成功")
        time.sleep(1)  # 等待视频播放


        time.sleep(0.5)
        driver.switch_to.window(driver.window_handles[-1])
    
    except Exception as e:
        print("未找到元素或元素不可用：", e)

    driver.switch_to.default_content()

print("所有标签页已打开并开始播放视频，请手动检查播放情况。")

    