#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
为文献综述生成汇报 PPT，风格参考 E:\filereceive\1_陈晓翀-第二次文献综述PPT.pptx
"""
import os
from pptx import Presentation
from pptx.util import Inches, Pt, Emu
from pptx.dml.color import RGBColor
from pptx.enum.text import PP_ALIGN, MSO_ANCHOR
from pptx.enum.shapes import MSO_SHAPE, MSO_CONNECTOR
from pptx.oxml.ns import nsmap

# ---------------------------------------------------------------------------
# 常量与主题
# ---------------------------------------------------------------------------
SLIDE_W = Inches(13.3333)
SLIDE_H = Inches(7.5)

CLR_TITLE = RGBColor(0x00, 0x00, 0x66)   # 深蓝标题
CLR_BLUE  = RGBColor(0x00, 0x51, 0x8E)   # 目录蓝
CLR_LBLUE = RGBColor(0x00, 0x00, 0xFF)   # 小标题蓝
CLR_RED   = RGBColor(0xFF, 0x00, 0x00)   # 强调红
CLR_BLACK = RGBColor(0x00, 0x00, 0x00)
CLR_DGRAY = RGBColor(0x33, 0x33, 0x33)

# 资源路径
ASSET_DIR = r"D:\Study\CUG_Automation\BUAA_Proposal_Template\.build_ppt\assets"
FIG_DIR   = r"D:\Study\CUG_Automation\BUAA_Proposal_Template\figs"
LOGO_PATH = os.path.join(ASSET_DIR, "5b72186e31_image.jpeg")
OUT_PATH  = r"D:\Study\CUG_Automation\BUAA_Proposal_Template\.build_ppt\output\无人机自主巡检文献综述_汇报.pptx"

# ---------------------------------------------------------------------------
# 字体设置辅助
# ---------------------------------------------------------------------------
from lxml import etree

def set_font(run, name, size, bold=False, color=CLR_BLACK, italic=False):
    run.font.name = name
    run.font.size = Pt(size)
    run.font.bold = bold
    run.font.italic = italic
    run.font.color.rgb = color
    # 让 Windows 在 CJK 环境正确选择中文字体
    rPr = run.font._rPr
    rPr.set('{http://schemas.openxmlformats.org/drawingml/2006/main}lang', 'zh-CN')
    # eastAsia 字体
    ea = rPr.find('{http://schemas.openxmlformats.org/drawingml/2006/main}ea')
    if ea is None:
        ea = etree.Element('{http://schemas.openxmlformats.org/drawingml/2006/main}ea')
        rPr.append(ea)
    ea.set('typeface', name)

# ---------------------------------------------------------------------------
# 基础元素
# ---------------------------------------------------------------------------
def add_top_bar(slide):
    """顶部左侧蓝色装饰条 + 右上角学校 logo"""
    # 左侧蓝色矩形
    shape = slide.shapes.add_shape(
        MSO_SHAPE.RECTANGLE, Inches(0.28), Inches(0.02), Inches(3.98), Inches(0.46)
    )
    shape.fill.solid()
    shape.fill.fore_color.rgb = RGBColor(0x00, 0x33, 0x66)
    shape.line.fill.background()
    shape.shadow.inherit = False

    # 右上角 logo
    if os.path.exists(LOGO_PATH):
        slide.shapes.add_picture(LOGO_PATH, Inches(9.27), Inches(0.02), width=Inches(3.98))

def add_title(slide, text, left=Inches(1.13), top=Inches(0.64), width=Inches(10.5), height=Inches(0.71)):
    tb = slide.shapes.add_textbox(left, top, width, height)
    tf = tb.text_frame
    tf.word_wrap = False
    p = tf.paragraphs[0]
    run = p.add_run()
    run.text = text
    set_font(run, '楷体', 36, bold=False, color=CLR_TITLE)
    p.alignment = PP_ALIGN.LEFT
    return tb

def add_line(slide, left=Inches(1.12), top=Inches(1.39), width=Inches(4.83)):
    line = slide.shapes.add_connector(
        MSO_CONNECTOR.STRAIGHT, left, top, left + width, top
    )
    line.line.color.rgb = CLR_TITLE
    line.line.width = Pt(2.0)
    return line

def add_page_num(slide, num):
    tb = slide.shapes.add_textbox(Inches(0.05), Inches(6.91), Inches(0.86), Inches(0.4))
    tf = tb.text_frame
    tf.word_wrap = False
    p = tf.paragraphs[0]
    run = p.add_run()
    run.text = str(num)
    set_font(run, '宋体', 14, color=CLR_DGRAY)
    p.alignment = PP_ALIGN.CENTER
    return tb

def new_slide(prs, title):
    blank = [l for l in prs.slide_layouts if l.name == 'Blank'][0]
    slide = prs.slides.add_slide(blank)
    add_top_bar(slide)
    if title:
        add_title(slide, title)
        add_line(slide)
    add_page_num(slide, len(prs.slides))
    return slide

def add_textbox(slide, x, y, w, h, text, font='宋体', size=18, color=CLR_DGRAY,
                bold=False, align=PP_ALIGN.LEFT, valign=MSO_ANCHOR.TOP,
                line_space=1.15, bullets=False):
    tb = slide.shapes.add_textbox(Inches(x), Inches(y), Inches(w), Inches(h))
    tf = tb.text_frame
    tf.word_wrap = True
    tf.margin_left = Pt(0)
    tf.margin_right = Pt(0)
    tf.margin_top = Pt(0)
    tf.margin_bottom = Pt(0)
    tf.auto_size = None
    lines = text.split('\n')
    for i, line in enumerate(lines):
        if i == 0:
            p = tf.paragraphs[0]
        else:
            p = tf.add_paragraph()
        p.level = 0
        p.space_after = Pt(6 if bullets else 0)
        p.line_spacing = line_space
        run = p.add_run()
        run.text = line.lstrip('- ')
        set_font(run, font, size, bold=bold, color=color)
        p.alignment = align
    tf.paragraphs[0].alignment = align
    return tb

def add_bullets(slide, x, y, w, h, items, font='宋体', size=18, color=CLR_DGRAY,
                title_text=None, title_font='黑体', title_size=20, title_color=CLR_LBLUE):
    """生成带小标题 bullet list 的文本框"""
    tb = slide.shapes.add_textbox(Inches(x), Inches(y), Inches(w), Inches(h))
    tf = tb.text_frame
    tf.word_wrap = True
    tf.margin_left = Pt(4)
    if title_text:
        p = tf.paragraphs[0]
        run = p.add_run()
        run.text = title_text
        set_font(run, title_font, title_size, bold=False, color=title_color)
        p.space_after = Pt(6)
    else:
        p = tf.paragraphs[0]
        p.text = ''
    for item in items:
        p = tf.add_paragraph()
        p.level = 0
        p.space_after = Pt(6)
        run = p.add_run()
        # 使用统一项目符号
        run.text = item
        set_font(run, font, size, color=color)
    return tb

def add_card(slide, x, y, w, h, title, body, fill=RGBColor(0xE6, 0xF0, 0xFA),
             title_color=CLR_LBLUE, body_color=CLR_DGRAY):
    shape = slide.shapes.add_shape(MSO_SHAPE.ROUNDED_RECTANGLE, Inches(x), Inches(y), Inches(w), Inches(h))
    shape.fill.solid()
    shape.fill.fore_color.rgb = fill
    shape.line.color.rgb = CLR_BLUE
    shape.line.width = Pt(1.0)
    tf = shape.text_frame
    tf.word_wrap = True
    tf.margin_left = Pt(8)
    tf.margin_right = Pt(8)
    tf.margin_top = Pt(8)
    tf.margin_bottom = Pt(8)
    p = tf.paragraphs[0]
    p.space_after = Pt(4)
    r = p.add_run(); r.text = title
    set_font(r, '黑体', 18, bold=False, color=title_color)
    for line in body.split('\n'):
        p = tf.add_paragraph()
        p.level = 0
        p.space_after = Pt(2)
        r = p.add_run(); r.text = line
        set_font(r, '宋体', 14, color=body_color)
    return shape

def add_arrow(slide, x1, y1, x2, y2, color=CLR_BLUE):
    """水平/垂直箭头，使用 RIGHT_ARROW 形状保证箭头可见"""
    width = abs(x2 - x1)
    height = max(0.25, abs(y2 - y1))
    left = min(x1, x2)
    top = min(y1, y2) - height / 2 + 0.1
    arrow = slide.shapes.add_shape(MSO_SHAPE.RIGHT_ARROW, Inches(left), Inches(top), Inches(width), Inches(height))
    arrow.fill.solid()
    arrow.fill.fore_color.rgb = color
    arrow.line.fill.background()
    return arrow

# ---------------------------------------------------------------------------
# 各页构建
# ---------------------------------------------------------------------------
def build_cover(prs):
    slide = new_slide(prs, '')
    # 大标题
    tb = slide.shapes.add_textbox(Inches(1.2), Inches(1.8), Inches(11.5), Inches(2.2))
    tf = tb.text_frame; tf.word_wrap = True
    p = tf.paragraphs[0]
    run = p.add_run()
    run.text = '面向复杂工业场景的\n无人机自主巡检关键技术\n文献综述'
    set_font(run, '楷体', 44, bold=False, color=CLR_TITLE)
    p.alignment = PP_ALIGN.CENTER
    p.line_spacing = 1.3

    # 副标题
    tb2 = slide.shapes.add_textbox(Inches(1.2), Inches(4.35), Inches(11.5), Inches(0.6))
    tf2 = tb2.text_frame; tf2.word_wrap = False
    p2 = tf2.paragraphs[0]
    r2 = p2.add_run(); r2.text = '文献综述汇报'
    set_font(r2, '宋体', 24, color=CLR_DGRAY)
    p2.alignment = PP_ALIGN.CENTER

    # 底部图片装饰
    img = os.path.join(FIG_DIR, 'fastlio2_aerial.png')
    if os.path.exists(img):
        slide.shapes.add_picture(img, Inches(8.0), Inches(4.9), width=Inches(4.0))

def build_toc(prs, highlight=0, title='目录'):
    """通用目录/过渡页：左侧标题，右侧目录列表，highlight 为当前章节索引（从0开始）"""
    slide = new_slide(prs, title)
    chapters = ['引言',
                '复杂工业场景与巡检任务',
                '环境感知与多模态融合',
                '工业设备缺陷与异常检测',
                '自主巡检规划与多机协同',
                '总结与展望']
    # 目录列表位置
    x0, y0 = 3.33, 1.9
    for i, ch in enumerate(chapters):
        y = y0 + i * 0.78
        # 编号圆圈
        circle = slide.shapes.add_shape(MSO_SHAPE.OVAL, Inches(2.64), Inches(y), Inches(0.58), Inches(0.58))
        circle.fill.solid()
        circle.fill.fore_color.rgb = CLR_BLUE if i == highlight else RGBColor(0xCC, 0xCC, 0xCC)
        circle.line.fill.background()
        tf = circle.text_frame
        tf.paragraphs[0].alignment = PP_ALIGN.CENTER
        r = tf.paragraphs[0].add_run(); r.text = str(i+1)
        set_font(r, '黑体', 18, bold=True, color=RGBColor(0xFF,0xFF,0xFF))
        # 章节名
        rect = slide.shapes.add_shape(MSO_SHAPE.RECTANGLE, Inches(x0), Inches(y), Inches(5.7), Inches(0.47))
        rect.fill.solid()
        rect.fill.fore_color.rgb = RGBColor(0xE6, 0xF0, 0xFA) if i == highlight else RGBColor(0xFF,0xFF,0xFF)
        rect.line.color.rgb = CLR_BLUE
        tf2 = rect.text_frame
        tf2.paragraphs[0].alignment = PP_ALIGN.LEFT
        r2 = tf2.paragraphs[0].add_run(); r2.text = '  ' + ch
        set_font(r2, '宋体', 22, bold=(i==highlight), color=CLR_BLUE)
        # 连接线
        if i < len(chapters) - 1:
            line = slide.shapes.add_connector(MSO_CONNECTOR.STRAIGHT,
                                              Inches(2.93), Inches(y+0.58),
                                              Inches(2.93), Inches(y+0.78))
            line.line.color.rgb = RGBColor(0x99,0x99,0x99)
            line.line.width = Pt(1.5)

def build_intro(prs):
    slide = new_slide(prs, '引言')
    bullets = [
        '电力、交通、能源等设施向规模化、复杂化发展，传统人工巡检在可达性、效率与一致性方面受限。',
        '无人机可搭载可见光、红外、激光雷达等传感器，成为工业巡检的重要数据获取平台。',
        '自主巡检不仅是“把相机装上无人机”，而是感知 → 异常认知 → 决策规划的闭环系统。',
        '核心挑战：GNSS 拒止、遮挡/弱纹理、缺陷样本稀缺、任务动态变化、多机协同。'
    ]
    add_bullets(slide, 1.1, 1.7, 6.0, 4.5, bullets, size=18)
    # 配图
    img = os.path.join(FIG_DIR, 'fastlio2_aerial.png')
    if os.path.exists(img):
        slide.shapes.add_picture(img, Inches(7.4), Inches(1.85), width=Inches(5.4))

def build_mainline(prs):
    """综述核心主线：感知—认知—决策闭环"""
    slide = new_slide(prs, '研究主线：感知—认知—决策闭环')
    # 三个主模块
    modules = [
        ('感知',
         '环境感知 + 多模态融合\n视觉 / 激光 / 惯性 / 红外\n输出：观测数据 + 不确定性',
         1.0),
        ('认知',
         '缺陷检测 + 异常检测\n监督 / 无监督 / 基础模型\n输出：异常位置 + 置信度',
         4.9),
        ('决策',
         '任务规划 + 多机协同\n覆盖 / 视点 / 重规划 / 分配\n输出：下一观测行为',
         8.8)
    ]
    for title, body, x in modules:
        add_card(slide, x, 2.0, 3.5, 2.6, title, body,
                 fill=RGBColor(0xE6, 0xF0, 0xFA),
                 title_color=CLR_TITLE, body_color=CLR_DGRAY)
    # 模块间箭头
    add_arrow(slide, 4.5, 3.25, 4.9, 3.25)
    add_arrow(slide, 8.4, 3.25, 8.8, 3.25)
    # 反馈箭头：决策 → 认知 → 感知（底部 U 型）
    down = slide.shapes.add_shape(MSO_SHAPE.DOWN_ARROW, Inches(10.4), Inches(4.5), Inches(0.3), Inches(0.8))
    down.fill.solid(); down.fill.fore_color.rgb = CLR_RED; down.line.fill.background()
    hline = slide.shapes.add_shape(MSO_SHAPE.RECTANGLE, Inches(2.75), Inches(5.25), Inches(7.8), Inches(0.08))
    hline.fill.solid(); hline.fill.fore_color.rgb = CLR_RED; hline.line.fill.background()
    up = slide.shapes.add_shape(MSO_SHAPE.UP_ARROW, Inches(2.6), Inches(4.5), Inches(0.3), Inches(0.8))
    up.fill.solid(); up.fill.fore_color.rgb = CLR_RED; up.line.fill.background()
    # 反馈说明
    add_textbox(slide, 1.0, 5.55, 11.3, 0.6,
                '检测结果驱动 → 生成复查视点/复检任务 → 更新感知与认知',
                font='黑体', size=18, color=CLR_RED, align=PP_ALIGN.CENTER)

def build_scenes(prs):
    slide = new_slide(prs, '复杂工业场景与巡检任务')
    # 三类场景卡片
    cards = [
        ('大范围开放/半开放设施',
         '• 输电线路、桥梁、风电、光伏\n• 覆盖与目标搜索\n• 观测距离、视场、分辨率权衡',
         RGBColor(0xE6, 0xF0, 0xFA)),
        ('受限或封闭工业空间',
         '• 隧道、压力钢管、管廊\n• GNSS 不可用、狭长空间\n• 近距离稳定运动与安全距离',
         RGBColor(0xE6, 0xFA, 0xF0)),
        ('感知退化环境',
         '• 低照度、强反光、粉尘、烟雾\n• 重复纹理、遮挡\n• 需多模态冗余维持连续感知',
         RGBColor(0xFA, 0xF0, 0xE6))
    ]
    for i, (title, body, fill) in enumerate(cards):
        add_card(slide, 0.9 + i*4.2, 1.7, 3.8, 2.3, title, body, fill=fill)
    # 任务层次箭头
    add_textbox(slide, 0.9, 4.35, 11.5, 0.45,
                '巡检任务三层次：环境/平台感知  →  巡检对象感知  →  状态信息获取',
                font='黑体', size=20, color=CLR_TITLE, align=PP_ALIGN.CENTER)
    # 三层卡片
    layer_texts = [
        ('环境与平台感知', '位姿估计\n障碍物感知\n可通行空间'),
        ('巡检对象感知', '设备搜索\n部件识别\n目标定位'),
        ('状态信息获取', '可见光 / 红外\n三维几何\n历史信息')
    ]
    for i, (t, b) in enumerate(layer_texts):
        add_card(slide, 0.9 + i*4.2, 4.9, 3.8, 1.8, t, b, fill=RGBColor(0xFF,0xFF,0xFF))
    # 箭头
    add_arrow(slide, 4.7, 5.8, 5.1, 5.8)
    add_arrow(slide, 8.9, 5.8, 9.3, 5.8)

def build_perception(prs):
    slide = new_slide(prs, '工业巡检环境感知')
    # 左侧技术演进
    timeline = [
        ('GNSS 辅助导航', '开阔环境全局位置'),
        ('视觉 SLAM', 'ORB-SLAM / VINS 系列，依赖纹理与光照'),
        ('激光-惯性里程计', 'LOAM / FAST-LIO2，几何稳定'),
        ('多传感器紧耦合', 'LVI-SAM / 2025 融合 SLAM 综述，模态互补')
    ]
    y = 1.75
    for i, (title, desc) in enumerate(timeline):
        # 步骤方块
        rect = slide.shapes.add_shape(MSO_SHAPE.ROUNDED_RECTANGLE,
                                      Inches(0.9), Inches(y + i*1.05), Inches(6.0), Inches(0.78))
        rect.fill.solid(); rect.fill.fore_color.rgb = RGBColor(0xE6,0xF0,0xFA)
        rect.line.color.rgb = CLR_BLUE
        tf = rect.text_frame
        p = tf.paragraphs[0]
        r = p.add_run(); r.text = f'{i+1}. {title}：{desc}'
        set_font(r, '宋体', 16, color=CLR_DGRAY)
    # 右侧配图
    img = os.path.join(FIG_DIR, 'fastlio2_overview.png')
    if os.path.exists(img):
        slide.shapes.add_picture(img, Inches(7.3), Inches(1.75), width=Inches(5.3))

def build_fusion(prs):
    slide = new_slide(prs, '多模态信息融合')
    # 三层金字塔
    levels = [
        ('数据级融合', '原始测量直接融合\n同步/标定要求高'),
        ('特征级融合', '各模态特征联合表达/状态估计'),
        ('决策级融合', '各模态结果组合')
    ]
    widths = [5.0, 7.5, 10.0]
    y_start = 1.8
    for i, (title, body) in enumerate(levels):
        w = widths[i]
        x = (12.5 - w) / 2
        y = y_start + i * 1.35
        rect = slide.shapes.add_shape(MSO_SHAPE.TRAPEZOID, Inches(x), Inches(y), Inches(w), Inches(1.1))
        rect.fill.solid(); rect.fill.fore_color.rgb = RGBColor(0xE6,0xF0,0xFA)
        rect.line.color.rgb = CLR_BLUE
        tf = rect.text_frame; tf.word_wrap = True
        p = tf.paragraphs[0]; p.alignment = PP_ALIGN.CENTER
        r = p.add_run(); r.text = title
        set_font(r, '黑体', 18, color=CLR_LBLUE)
        p2 = tf.add_paragraph(); p2.alignment = PP_ALIGN.CENTER
        r2 = p2.add_run(); r2.text = body
        set_font(r2, '宋体', 14, color=CLR_DGRAY)
    # 架构说明
    add_textbox(slide, 0.9, 6.0, 11.5, 0.5,
                '工程架构：松耦合（分别估计再融合） vs. 紧耦合（统一滤波/优化/因子图）',
                font='黑体', size=18, color=CLR_RED, align=PP_ALIGN.CENTER)

def build_defect_supervised(prs):
    slide = new_slide(prs, '工业缺陷检测：监督式方法')
    bullets = [
        '目标检测：Faster R-CNN、YOLO 系列、SSD，兼顾精度与实时性。',
        '多尺度与类别不平衡：Focal Loss、特征金字塔，应对裂纹/小目标。',
        'Transformer 检测：DETR、Deformable DETR、Swin Transformer，引入全局关系。',
        '轻量化部署：MobileNet、EfficientNet，平衡机载算力与续航。',
        '局限：依赖大量缺陷标注，难以适应新设备、新缺陷、视角变化。'
    ]
    add_bullets(slide, 0.9, 1.7, 6.5, 4.8, bullets, size=18)
    img = os.path.join(FIG_DIR, 'fasterrcnn_model.png')
    if os.path.exists(img):
        slide.shapes.add_picture(img, Inches(7.6), Inches(1.7), width=Inches(5.0))

def build_anomaly(prs):
    slide = new_slide(prs, '小样本与无监督异常检测')
    bullets = [
        '重建模型：VAE、GAN — 利用重建误差判断异常。',
        '单类特征建模：Deep SVDD、PatchCore、PaDiM — 预训练特征 + 正常样本记忆库。',
        '知识蒸馏/归一化流：RD、FastFlow、EfficientAD — 降低推理成本。',
        '自监督/合成异常：CutPaste、DRAEM — 仅使用正常样本构造训练信号。',
        '基础模型：CLIP / WinCLIP — 零样本/少样本异常识别。',
        '关键难点：公开数据集与真实巡检条件存在差距，正常分布本身会随工况变化。'
    ]
    add_bullets(slide, 0.9, 1.65, 6.2, 5.0, bullets, size=17)
    img = os.path.join(FIG_DIR, 'patchcore_samples.png')
    if os.path.exists(img):
        slide.shapes.add_picture(img, Inches(7.4), Inches(1.7), width=Inches(5.4))

def build_multimodal_anomaly(prs):
    slide = new_slide(prs, '多模态异常认知')
    # 三列
    cols = [
        ('可见光', '裂纹、腐蚀\n表面剥落', RGBColor(0xFF,0xF0,0xE6)),
        ('热红外', '光伏热斑\n电气设备过热', RGBColor(0xFF,0xE6,0xE6)),
        ('三维几何', '凹陷、变形\n缺失、装配偏差', RGBColor(0xE6,0xF0,0xFA))
    ]
    for i, (t, b, fill) in enumerate(cols):
        add_card(slide, 0.9 + i*4.2, 1.75, 3.8, 2.2, t, b, fill=fill)
    # 底部文字
    add_textbox(slide, 0.9, 4.25, 11.5, 0.5,
                '多模态融合不是简单拼接，而是根据缺陷机理选择能够有效降低状态不确定性的信息。',
                font='黑体', size=18, color=CLR_RED, align=PP_ALIGN.CENTER)
    # 配图
    img = os.path.join(FIG_DIR, 'draem_qualitative.png')
    if os.path.exists(img):
        slide.shapes.add_picture(img, Inches(8.0), Inches(4.9), width=Inches(4.5))

def build_planning(prs):
    slide = new_slide(prs, '自主巡检任务规划')
    # 左侧流程
    steps = [
        ('传统路径规划', '点到点可行运动'),
        ('覆盖路径规划', '区域覆盖、路径长度、能耗'),
        ('面向目标的视点规划', '相机视场、观测距离、机动性约束'),
        ('下一最佳视点 NBV', '未知区域/重建误差/信息增益驱动'),
        ('动态路径重规划', '滚动时域、实时避障、感知-决策闭环')
    ]
    y = 1.75
    for i, (title, desc) in enumerate(steps):
        rect = slide.shapes.add_shape(MSO_SHAPE.ROUNDED_RECTANGLE,
                                      Inches(0.9), Inches(y + i*0.95), Inches(6.3), Inches(0.72))
        rect.fill.solid(); rect.fill.fore_color.rgb = RGBColor(0xE6,0xF0,0xFA)
        rect.line.color.rgb = CLR_BLUE
        tf = rect.text_frame
        r = tf.paragraphs[0].add_run()
        r.text = f'{i+1}. {title}：{desc}'
        set_font(r, '宋体', 16, color=CLR_DGRAY)
        if i < len(steps)-1:
            line = slide.shapes.add_shape(MSO_SHAPE.RIGHT_ARROW, Inches(3.5), Inches(y + i*0.95 + 0.72), Inches(0.7), Inches(0.23))
            line.fill.solid(); line.fill.fore_color.rgb = CLR_BLUE
            line.line.fill.background()
    img = os.path.join(FIG_DIR, 'rrtstar_10000.png')
    if os.path.exists(img):
        slide.shapes.add_picture(img, Inches(7.5), Inches(1.75), width=Inches(5.3))

def build_coordination(prs):
    slide = new_slide(prs, '多无人机协同决策')
    bullets = [
        '集中式任务分配：整数规划/组合优化，全局较优但规模受限。',
        '分布式协商：CBBA 拍卖机制，无需中心节点，适合动态任务。',
        '异构资源匹配：续航、载荷、传感器差异决定平台-任务适配。',
        '通信约束：金属结构遮挡、数据带宽限制，需权衡共享信息量。',
        '任务-轨迹联合优化：输电线路风场影响、风电机组 STL 约束。',
        '动态任务生成：异常复查任务在线产生，需实时重分配。'
    ]
    add_bullets(slide, 0.9, 1.7, 6.0, 4.8, bullets, size=17)
    img = os.path.join(FIG_DIR, 'swarm_head.png')
    if os.path.exists(img):
        slide.shapes.add_picture(img, Inches(7.3), Inches(1.7), width=Inches(5.5))

def build_summary(prs):
    slide = new_slide(prs, '总结与展望')
    # 左栏：5个问题
    problems = [
        '感知可靠性缺少面向任务的不确定性描述',
        '异常检测结果未充分转化为巡检行为',
        '规划仍多依赖预先确定的任务集合',
        '多机协同对感知结果利用不足',
        '真实工业场景系统级验证仍不足'
    ]
    add_bullets(slide, 0.8, 1.65, 5.8, 5.2, problems,
                title_text='现有研究存在的主要问题', title_color=CLR_RED, size=17)
    # 右栏：5个方向
    directions = [
        '任务驱动的多模态信息选择与融合',
        '异常驱动的主动复查闭环机制',
        '信息价值驱动的动态巡检规划',
        '动态任务生成的多无人机协同',
        '真实环境下的系统级验证与统一评价'
    ]
    add_bullets(slide, 6.9, 1.65, 5.8, 5.2, directions,
                title_text='下一步研究方向', title_color=CLR_LBLUE, size=17)

def build_thanks(prs):
    slide = new_slide(prs, '')
    tb = slide.shapes.add_textbox(Inches(3.3), Inches(2.8), Inches(8.0), Inches(1.9))
    tf = tb.text_frame; tf.word_wrap = True
    p = tf.paragraphs[0]; p.alignment = PP_ALIGN.CENTER
    r = p.add_run(); r.text = '谢谢！\n请各位老师批评指正！'
    set_font(r, '黑体', 54, bold=True, color=CLR_TITLE)
    p.line_spacing = 1.4

def check_geometry(prs):
    """检查所有形状是否越界或存在明显重叠"""
    W = prs.slide_width
    H = prs.slide_height
    tol = 0.0
    for i, slide in enumerate(prs.slides, 1):
        for sh in slide.shapes:
            try:
                l, t, w, h = sh.left, sh.top, sh.width, sh.height
                if l is None or t is None or w is None or h is None:
                    continue
                r = l + w
                b = t + h
                if l < -tol or t < -tol or r > W + tol or b > H + tol:
                    print(f'[警告] 第{i}页 shape {sh.name} 越界: '
                          f'({l/914400:.2f},{t/914400:.2f},{r/914400:.2f},{b/914400:.2f})')
            except Exception as e:
                print(f'[跳过] 第{i}页 shape {sh.name}: {e}')

# ---------------------------------------------------------------------------
# 主函数
# ---------------------------------------------------------------------------
def main():
    prs = Presentation()
    prs.slide_width = SLIDE_W
    prs.slide_height = SLIDE_H

    build_cover(prs)
    build_toc(prs, highlight=-1, title='目录')
    build_intro(prs)
    build_mainline(prs)

    build_toc(prs, highlight=1, title='目录')
    build_scenes(prs)

    build_toc(prs, highlight=2, title='目录')
    build_perception(prs)
    build_fusion(prs)

    build_toc(prs, highlight=3, title='目录')
    build_defect_supervised(prs)
    build_anomaly(prs)
    build_multimodal_anomaly(prs)

    build_toc(prs, highlight=4, title='目录')
    build_planning(prs)
    build_coordination(prs)

    build_toc(prs, highlight=5, title='目录')
    build_summary(prs)
    build_thanks(prs)

    # 重新写入页码（因为 new_slide 只在添加时编号）
    # 但页码已经是按添加顺序，正确。

    check_geometry(prs)
    prs.save(OUT_PATH)
    print('PPT 已保存到', OUT_PATH)

if __name__ == '__main__':
    main()
