import os
import shutil
import glob

def move_html_files(source_dir, target_dir):
    # 创建目标目录
    os.makedirs(target_dir, exist_ok=True)

    # 使用通配符路径获取匹配的目录路径列表
    dirs = glob.glob(os.path.join(source_dir, "*/"))

    for dir_path in dirs:
        # 将源目录名替换为目标目录名
        target_path = dir_path.replace(source_dir, target_dir)
        # 如果目标目录不存在，则创建目录
        if not os.path.exists(target_path):
            os.makedirs(target_path)

        # 获取目录下的所有HTML文件
        html_files = glob.glob(os.path.join(dir_path, "*.html"))

        for file_path in html_files:
            # 获取文件名
            file_name = os.path.basename(file_path)

            # 移动文件到目标目录
            shutil.move(file_path, os.path.join(target_path, file_name))

# 调用函数进行移动
source_directory = "notes/"
target_directory = "docs/"
move_html_files(source_directory, target_directory)