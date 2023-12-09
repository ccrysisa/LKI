import os
import shutil
import glob

def convert_html_url(html_file, repo_url):
    # 读取 HTML 文件内容
    with open(html_file, "r") as file:
        content = file.read()
    
    # 替换相对路径为绝对路径
    new_content = content.replace('href="../../tests/', f'href="{repo_url}/tests/')

    # 将修改后的HTML写回文件
    with open(html_file, "w") as file:
        file.write(new_content)

def move_html_files(source_dir, target_dir):
    # 创建目标目录
    os.makedirs(target_dir, exist_ok=True)

    # 使用通配符路径获取匹配的目录路径列表
    dirs = glob.glob(os.path.join(source_dir, "*/"))

    for dir_path in dirs:

        # 获取目录下的所有HTML文件
        html_files = glob.glob(os.path.join(dir_path, "*.html"))

        for file_path in html_files:
            # 转换 HTML 中的引用路径
            convert_html_url(file_path, repo_url)

            # 获取文件名
            file_name = os.path.basename(file_path)

            # 移动文件到目标目录
            shutil.move(file_path, os.path.join(target_dir, file_name))

# 调用函数进行移动
source_directory = "notes/"
target_directory = "docs/"
repo_url = "https://github.com/LoongGshine/LKI/blob/main"
move_html_files(source_directory, target_directory)