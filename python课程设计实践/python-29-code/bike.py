import pandas as pd
import matplotlib.pyplot as plt
import os

# 防止中文出现乱码
plt.rcParams['font.sans-serif'] = ['SimHei']  # 黑体
plt.rcParams['axes.unicode_minus'] = False

# 任务1：读取数据并查看前5行和后2行
def read_and_preview_data():
    file_name = input('请输入要打开的文件名bike_day.csv:')
    try:
        df = pd.read_csv(file_name)
        print("前5行数据：")
        print(df.head(5))
        print("后2行数据：")
        print(df.tail(2))
        print("任务1执行成功!")
    except Exception as e:
        print(f'任务1执行失败: {e}')

# 任务2：选择特定列并处理缺失值
def select_and_export_data():
    file_name = input('请输入要打开的文件名bike_day.csv:')
    try:
        df = pd.read_csv(file_name)
        df_selected = df[['instant', 'dteday', 'atemp', 'casual', 'registered']].dropna()
        df_selected.to_csv('bike_atemp_user.txt', sep=' ', index=False, lineterminator='\n')
        print("任务2执行成功!")
    except Exception as e:
        print(f'任务2执行失败: {e}')

# 任务3：计算新列并导出为Excel文件
def calculate_and_export_data():
    file_name = input('请输入要打开的文件名bike_atemp_user.txt:')
    try:
        df = pd.read_csv(file_name, sep=' ')
        df['cnt'] = df['casual'] + df['registered']
        df.to_excel('bike_atemp_user_cnt.xlsx', index=False)
        print("任务3执行成功!")
    except Exception as e:
        print(f'任务3执行失败: {e}')

# 任务4：离散化数据并导出为CSV文件
def discretize_and_export_data():
    file_name = input('请输入要打开的文件名bike_atemp_user_cnt.xlsx:')
    try:
        df = pd.read_excel(file_name)
        maxValue = df['atemp'].max()
        minValue = df['atemp'].min()
        meanValue = df['atemp'].mean()
        category = [minValue, 0.4, 0.6, 0.8, maxValue]
        labels = ['Cold', 'Cool', 'Warm', 'Hot']
        df['Label'] = pd.cut(df['atemp'], bins=category, labels=labels, right=False)
        df.to_csv('bike_atemp_user_cnt_result.csv', index=False)
        print("任务4执行成功!")
    except Exception as e:
        print(f'任务4执行失败: {e}')

# 任务5：可视化数据并保存为图片
def visualize_data():
    file_name = input('请输入要打开的文件名bike_atemp_user_cnt_result.csv:')
    try:
        df = pd.read_csv(file_name)
        df_grouped = df.groupby('Label')['cnt'].mean()

        plt.figure(figsize=(10, 6))
        df_grouped.plot(kind='bar', color='blue')
        plt.xlabel('Label', fontsize=12)
        plt.ylabel('Average Count', fontsize=12)
        plt.title('Average Bike Rentals by Temperature Category', fontsize=16)
        plt.xticks(rotation=0)
        plt.savefig('bike_atemp_user_cnt.png', dpi=300)
        plt.show()

        print("任务5执行成功!")
    except Exception as e:
        print(f'任务5执行失败: {e}')

# 系统主界面
def menu():
    print('【任务选择】\n'
          '+----共享单车租赁数据分析及可视化系统---------+\n'
          '|0、退出。\n'
          '|1、数据读取及预览。\n'
          '|2、数据选择及导出。\n'
          '|3、计算新列并导出。\n'
          '|4、离散化数据并导出。\n'
          '|5、数据可视化。\n'
          '+------------------------------------------+')

# 功能选择模块
def task():
    while True:
        menu()  # 打印系统主界面
        num = input("请输入任务选项：")
        if num == '1':
            read_and_preview_data()
        elif num == '2':
            select_and_export_data()
        elif num == '3':
            calculate_and_export_data()
        elif num == '4':
            discretize_and_export_data()
        elif num == '5':
            visualize_data()
        elif num == '0':
            print('程序结束!')
            break
        else:
            print('输入选项有误')
        input("回车显示菜单")

# 主函数
if __name__ == '__main__':
    task()