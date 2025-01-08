## Usage of the code

The presented code is based on MATLAB and consists of three m files. main.m is responsible for solving ODE and plotting figures. drilling.m contains the state-space model of drill-string and observer, as well as the bit-rock interaction model described by Karnopp model. LQR_PolePlacement.m has two functions. One is used to calculate the expected state-feedback gains using LQR method. Another one computes the observer gain by employing pole placement method.

For a better understanding of this code, one can refer to the conference paper <a href="https://ieeexplore.ieee.org/abstract/document/8483801">Observer-Based Tracking Control for Suppressing Stick-Slip Vibration of Drillstring System</a> and <a href="https://ieeexplore.ieee.org/document/4282198">Sliding-mode control of a multi-DOF oilwell drillstring with stick-slip oscillations</a>.
