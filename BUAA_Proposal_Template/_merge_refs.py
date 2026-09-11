# -*- coding: utf-8 -*-
import os, re

BASE = r"D:\Study\CUG_Automation\BUAA_Proposal_Template"
REF = os.path.join(BASE, "refs.bib")
NEW = os.path.join(BASE, "content", "_new_refs.bib")
RW  = os.path.join(BASE, "content", "related_work.tex")

USED = {
 "nooralishahi2021drones","safie2025trip","nooralishahi2022access",
 "jarraya2025gnssdenied","boiteau2024uavlowvisibility","zhao2024uavresilient","zhao2025resilient",
 "alradi2023iecon","oliveira2023pvairt","zefri2023pvlwir","yu2021rcar","alsayed2021rs",
 "shan2020liosam","wu2025dalislam","kim2024adaptiveuavlio","lin2022r3live","zheng2025fastlivo2",
 "pfreundschuh2024coinlio","zhang2024lviofusion","wang2024dynamicsurvey","bolourian2020lidarbridge",
 "xu2023tunnelinspection","li2024multispectraldefect","hua2025aerialsmall","zhang2025lowaltitudeuav",
 "zhu2021visdrone","shukla2025iadsurvey","li2025iadreview","tan2024sccmdet","yi2025uavtransmission",
 "xiao2024bridgeroicrack","wang2024steelcorrosion","maboudi2025bridgedeformation","hang2024wtbcrack",
 "santos2024uvthermopl","liu2025infraredcsee","ertunc2024thermalfault","liu2023simplenet","coscia2025onen",
 "zhu2024inctrl","li2024musc","zhou2024anomalyclip","ma2025aaclip","li2025mulsenad","zhang2026continualad",
 "mao2023powerinspection","zhao2024structuralinspection","wang2025uavsurface","jung2024bridgepose",
 "gazani2023bagofviews","ortega2020aiaa","ruckin2022adaptiveipp","petit2024moar","westheider2023multiipp",
 "ivic2023multiuavinspection","gilcastilla2024hetero","jeong2023makespan","obrien2023dynamictask",
 "fei2022limitedcomm","jacobsen2023swarm","pan2024uhcrp","kulkarni2022teamed",
}

def extract_entry(path, key):
    txt = open(path, encoding='utf-8').read()
    m = re.search(r'@\w+\s*\{'+re.escape(key)+r',', txt)
    if not m:
        return None
    i = m.start()
    j = txt.find('{', i)
    depth, p, n = 0, j, len(txt)
    while p < n:
        if txt[p] == '{': depth += 1
        elif txt[p] == '}':
            depth -= 1
            if depth == 0:
                break
        p += 1
    return txt[i:p+1]

# ---- append used entries to refs.bib (idempotent) ----
MARKER = "% ================= Added from _new_refs.bib (verified real) ================="
ref_txt = open(REF, encoding='utf-8').read()
if MARKER in ref_txt:
    print("refs.bib already contains appended block; skipping re-append.")
else:
    extracted = {}
    for k in sorted(USED):
        e = extract_entry(NEW, k)
        assert e is not None, f"could not extract {k}"
        assert e.rstrip().endswith('}'), f"entry {k} not balanced"
        extracted[k] = e
    add_block = "\n\n" + MARKER + "\n"
    for k in sorted(USED):
        add_block += "\n" + extracted[k].rstrip() + "\n"
    open(REF, 'w', encoding='utf-8').write(ref_txt + add_block)
    print("appended", len(extracted), "entries to refs.bib")

# ---- citation insertions into related_work.tex ----
# Each entry: (exact old substring as it appears in the file, replacement).
# Anchors verified against the current file; old strings are unique (count==1).
REPL = [
 # L4  UAV as data-acquisition platform
 (r"\cite{Nguyen2018PowerLine,Ahmed2020BridgeNDE,Zhang2022UBI,Panigati2025Bridge,Yahya2022PVReview,Shakhatreh2019UAV}",
  r"\cite{Nguyen2018PowerLine,Ahmed2020BridgeNDE,Zhang2022UBI,Panigati2025Bridge,Yahya2022PVReview,Shakhatreh2019UAV,nooralishahi2021drones,safie2025trip,nooralishahi2022access}"),
 # L10 GNSS-denied difficulties
 (r"\cite{Ozaslan2017Penstocks,Chang2023GNSSDenied,Zhao2024ResilientUAV}",
  r"\cite{Ozaslan2017Penstocks,Chang2023GNSSDenied,Zhao2024ResilientUAV,jarraya2025gnssdenied,boiteau2024uavlowvisibility}"),
 # L12 resilient/long-term autonomous operation
 (r"\cite{Zhao2024ResilientUAV,Li2025UAVFusion,Zhang2022UBI,Alqudsi2026GNSSDenied}",
  r"\cite{Zhao2024ResilientUAV,Li2025UAVFusion,Zhang2022UBI,Alqudsi2026GNSSDenied,zhao2024uavresilient,zhao2025resilient}"),
 # L22 application coverage
 (r"\cite{Nguyen2018PowerLine,Jeong2020BridgeReview,Falorca2020Facade,Ozaslan2017Penstocks,Liu2022WindRobots,Yahya2022PVReview}",
  r"\cite{Nguyen2018PowerLine,Jeong2020BridgeReview,Falorca2020Facade,Ozaslan2017Penstocks,Liu2022WindRobots,Yahya2022PVReview,nooralishahi2021drones,safie2025trip,alradi2023iecon}"),
 # L24 PV thermal/crack/defect
 (r"识别热异常、裂纹和组件缺陷\cite{Yahya2022PVReview,Ramirez2022PVRTK}.",
  r"识别热异常、裂纹和组件缺陷\cite{Yahya2022PVReview,Ramirez2022PVRTK,oliveira2023pvairt,zefri2023pvlwir}."),
 # L26 confined-space mapping
 (r"环境建图\cite{Ozaslan2017Penstocks}。",
  r"环境建图\cite{Ozaslan2017Penstocks,yu2021rcar,alsayed2021rs}。"),
 # L28 resilience at local failure (no prior cite)
 (r"局部失效或数据质量下降时能否维持连续运行。",
  r"局部失效或数据质量下降时能否维持连续运行\cite{Zhao2024ResilientUAV,boiteau2024uavlowvisibility}。"),
 # L30 task hierarchy
 (r"\cite{Zhang2022UBI,Nguyen2018PowerLine,Yahya2022PVReview}",
  r"\cite{Zhang2022UBI,Nguyen2018PowerLine,Yahya2022PVReview,nooralishahi2021drones}"),
 # L38 GNSS-denied positioning
 (r"\cite{Chang2023GNSSDenied,Zhao2024ResilientUAV,Alqudsi2026GNSSDenied}",
  r"\cite{Chang2023GNSSDenied,Zhao2024ResilientUAV,Alqudsi2026GNSSDenied,jarraya2025gnssdenied,zhao2024uavresilient}"),
 # L44 FAST-LIO2 / LI-SAM family
 (r"减少了对手工几何特征提取的依赖\cite{Xu2022FASTLIO2}；",
  r"减少了对手工几何特征提取的依赖\cite{Xu2022FASTLIO2,shan2020liosam,wu2025dalislam,kim2024adaptiveuavlio}；"),
 # L46 triple-coupling / multi-modal dependency
 (r"降低系统对单一模态的依赖\cite{Fan2025FusionSLAM}.",
  r"降低系统对单一模态的依赖\cite{Fan2025FusionSLAM,lin2022r3live,zheng2025fastlivo2,pfreundschuh2024coinlio,zhang2024lviofusion}."),
 # L48 dynamic environments as key problem
 (r"\cite{Chang2023GNSSDenied,Alqudsi2026GNSSDenied}",
  r"\cite{Chang2023GNSSDenied,Alqudsi2026GNSSDenied,wang2024dynamicsurvey}"),
 # L50 engineering task-driven perception
 (r"\cite{Ozaslan2017Penstocks,Zhang2022UBI,Ahmed2024Transmission,Yahya2022PVReview}",
  r"\cite{Ozaslan2017Penstocks,Zhang2022UBI,Ahmed2024Transmission,Yahya2022PVReview,bolourian2020lidarbridge,xu2023tunnelinspection}"),
 # L66 complementary visible/IR info
 (r"两类信息具有明显的互补性\cite{Yahya2022PVReview,Ramirez2022PVRTK}。",
  r"两类信息具有明显的互补性\cite{Yahya2022PVReview,Ramirez2022PVRTK,oliveira2023pvairt,zefri2023pvlwir,li2024multispectraldefect}。"),
 # L70 resilient fusion framework
 (r"无人机韧性自主定位研究已经将感知退化、鲁棒估计和多源冗余信息融合放在同一框架中讨论\cite{Zhao2024ResilientUAV}.",
  r"无人机韧性自主定位研究已经将感知退化、鲁棒估计和多源冗余信息融合放在同一框架中讨论\cite{Zhao2024ResilientUAV,zhao2025resilient,jarraya2025gnssdenied}."),
 # L80 defect vs natural-scene detection
 (r"\cite{Nguyen2018PowerLine,Jeong2020BridgeReview,Zhang2022UBI,Yahya2022PVReview}",
  r"\cite{Nguyen2018PowerLine,Jeong2020BridgeReview,Zhang2022UBI,Yahya2022PVReview,hua2025aerialsmall,zhang2025lowaltitudeuav,zhu2021visdrone}"),
 # L82 image/object/pixel-level defect detection
 (r"\cite{Diers2023IJCVIQC,Taox2021Survey}",
  r"\cite{Diers2023IJCVIQC,Taox2021Survey,shukla2025iadsurvey,li2025iadreview}"),
 # L88 YOLO family / real-time
 (r"在推理速度方面更适合实时视觉应用\cite{Redmon2016YOLO,Redmon2018YOLOv3,Bochkovskiy2020YOLOv4}.",
  r"在推理速度方面更适合实时视觉应用\cite{Redmon2016YOLO,Redmon2018YOLOv3,Bochkovskiy2020YOLOv4,tan2024sccmdet,yi2025uavtransmission}."),
 # L96 bridge defect detection examples (distributed across 4 cites)
 (r"\cite{Yeum2015Vision}.",
  r"\cite{Yeum2015Vision,xiao2024bridgeroicrack}."),
 (r"\cite{Cha2017Deep}.",
  r"\cite{Cha2017Deep,wang2024steelcorrosion}."),
 (r"\cite{Liu2020BridgeCrack}.",
  r"\cite{Liu2020BridgeCrack,maboudi2025bridgedeformation}."),
 (r"\cite{Tao2020Insulator}.",
  r"\cite{Tao2020Insulator,hang2024wtbcrack}."),
 # L100 visible/IR/3D complementarity
 (r"\cite{Jadin2012Infrared,Usamentiaga2014Infrared,Ramirez2022PVRTK}.",
  r"\cite{Jadin2012Infrared,Usamentiaga2014Infrared,Ramirez2022PVRTK,santos2024uvthermopl,liu2025infraredcsee,ertunc2024thermalfault,li2024multispectraldefect}."),
 # L106 normal-sample modeling / AD surveys
 (r"\cite{Pang2021DeepAD,Diers2023IJCVIQC,Liu2024IADSurvey}",
  r"\cite{Pang2021DeepAD,Diers2023IJCVIQC,Liu2024IADSurvey,li2025iadreview,shukla2025iadsurvey}"),
 # L114 MVTec AD dataset (+ pre-existing uncited Wang2024RealIAD)
 (r"\cite{Bergmann2019MVTec}.",
  r"\cite{Bergmann2019MVTec,Wang2024RealIAD}."),
 # L116 knowledge distillation / EfficientAD
 (r"\cite{Batzner2024EfficientAD}.",
  r"\cite{Batzner2024EfficientAD,liu2023simplenet,coscia2025onen}."),
 # L118 self-supervised cutpaste/draem
 (r"\cite{Li2021CutPaste}.",
  r"\cite{Li2021CutPaste,zhu2024inctrl}."),
 (r"\cite{Zavrtanik2021DRAEM}.",
  r"\cite{Zavrtanik2021DRAEM,li2024musc}."),
 # L120 CLIP / WinCLIP
 (r"\cite{Radford2021CLIP}.",
  r"\cite{Radford2021CLIP,zhou2024anomalyclip}."),
 (r"\cite{Jeong2023WinCLIP}.",
  r"\cite{Jeong2023WinCLIP,ma2025aaclip}."),
 # L122 RGB->3D/multi-modal AD
 (r"\cite{Bergmann2021MVTec3D,Li2025RGB3D}.",
  r"\cite{Bergmann2021MVTec3D,Li2025RGB3D,li2025mulsenad}."),
 # L124 AutoVI / IQC gap
 (r"\cite{Carvalho2024AutoVI}.",
  r"\cite{Carvalho2024AutoVI,shukla2025iadsurvey}."),
 # L128 summary of AD
 (r"\cite{Li2025IADSurvey,Li2025RGB3D,Mao2025IADSurvey}.",
  r"\cite{Li2025IADSurvey,Li2025RGB3D,Mao2025IADSurvey,zhang2026continualad,zhu2024inctrl}."),
 # L134 classical planning (3 groups)
 (r"\cite{LaValle2006,Karaman2011,Kingston2018}",
  r"\cite{LaValle2006,Karaman2011,Kingston2018,mao2023powerinspection,bolourian2020lidarbridge,zhao2024structuralinspection,wang2025uavsurface}"),
 (r"\cite{Galceran2013,Cabreira2019,Zeng2020}",
  r"\cite{Galceran2013,Cabreira2019,Zeng2020,wang2025uavsurface,jung2024bridgepose,gazani2023bagofviews,bolourian2020lidarbridge}"),
 (r"\cite{Gerkey2004,Chakraa2023,Skaltsis2023}",
  r"\cite{Gerkey2004,Chakraa2023,Skaltsis2023,ivic2023multiuavinspection,gilcastilla2024hetero,jeong2023makespan,obrien2023dynamictask}"),
 # L138 coverage path planning
 (r"\cite{Choset2001,Galceran2013}",
  r"\cite{Choset2001,Galceran2013,zhao2024structuralinspection}"),
 # L140 viewpoint planning (Zeng2020 group)
 (r"\cite{Zeng2020}",
  r"\cite{Zeng2020,wang2025uavsurface,jung2024bridgepose,gazani2023bagofviews,bolourian2020lidarbridge}"),
 # L142 offline model-driven -> online (ortega2020aiaa)
 (r"离线模型驱动的规划更适合作为初始方案，实际执行仍需要在线调整。",
  r"离线模型驱动的规划更适合作为初始方案，实际执行仍需要在线调整\cite{ortega2020aiaa}。"),
 # L144 next-best-view
 (r"\cite{Bircher2016,Zeng2020}.",
  r"\cite{Bircher2016,Zeng2020,gazani2023bagofviews,ruckin2022adaptiveipp}."),
 # L148 receding horizon
 (r"\cite{Papaioannou2022}",
  r"\cite{Papaioannou2022,petit2024moar,ruckin2022adaptiveipp}"),
 # L150 RL planning
 (r"\cite{Kober2013}",
  r"\cite{Kober2013,westheider2023multiipp,ruckin2022adaptiveipp}"),
 # L156 multi-robot task allocation
 (r"\cite{Gerkey2004,Chakraa2023}",
  r"\cite{Gerkey2004,Chakraa2023,ivic2023multiuavinspection,gilcastilla2024hetero,jeong2023makespan,obrien2023dynamictask}"),
 # L162 dynamic task allocation (+ pre-existing uncited Song2023MultiUAVMission)
 (r"\cite{Alqefari2025}",
  r"\cite{Alqefari2025,obrien2023dynamictask,fei2022limitedcomm,Song2023MultiUAVMission}"),
 # L164 heterogeneous resources
 (r"\cite{Dong2025}",
  r"\cite{Dong2025,jacobsen2023swarm,gilcastilla2024hetero,jeong2023makespan}"),
 # L166 task allocation + trajectory coupling
 (r"\cite{Li2024Wind}",
  r"\cite{Li2024Wind,ivic2023multiuavinspection}"),
 # L168 communication-efficient CBBA
 (r"\cite{Kim2020}",
  r"\cite{Kim2020,fei2022limitedcomm,pan2024uhcrp}"),
 # L170 safety-constrained learning (no prior cite)
 (r"对于工业巡检这种具有安全约束的任务，仅依靠经验策略难以形成充分的工程保证，因此较具应用前景的方案仍需要将学习策略与任务约束、能源限制和碰撞约束结合。",
  r"对于工业巡检这种具有安全约束的任务，仅依靠经验策略难以形成充分的工程保证，因此较具应用前景的方案仍需要将学习策略与任务约束、能源限制和碰撞约束结合\cite{westheider2023multiipp,kulkarni2022teamed}。"),
]

rw = open(RW, encoding='utf-8').read()
fails = []
for old, new in REPL:
    c = rw.count(old)
    if c != 1:
        fails.append((c, old))
if fails:
    print("=== ANCHOR FAILURES ===")
    for c, old in fails:
        print(f"count={c}: {old[:110]}")
    raise SystemExit("fix above anchors before writing")

for old, new in REPL:
    rw = rw.replace(old, new, 1)

open(RW, 'w', encoding='utf-8').write(rw)
print("inserted", len(REPL), "citation anchors into related_work.tex")
