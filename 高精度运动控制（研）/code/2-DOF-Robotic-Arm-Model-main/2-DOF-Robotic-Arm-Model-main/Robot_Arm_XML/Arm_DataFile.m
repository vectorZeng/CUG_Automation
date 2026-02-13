% Simscape(TM) Multibody(TM) version: 23.2

% This is a model data file derived from a Simscape Multibody Import XML file using the smimport function.
% The data in this file sets the block parameter values in an imported Simscape Multibody model.
% For more information on this file, see the smimport function help page in the Simscape Multibody documentation.
% You can modify numerical values, but avoid any other changes to this file.
% Do not add code to this file. Do not edit the physical units shown in comments.

%%%VariableName:smiData


%============= RigidTransform =============%

%Initialize the RigidTransform structure array by filling in null values.
smiData.RigidTransform(7).translation = [0.0 0.0 0.0];
smiData.RigidTransform(7).angle = 0.0;
smiData.RigidTransform(7).axis = [0.0 0.0 0.0];
smiData.RigidTransform(7).ID = "";

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(1).translation = [0 100 5.0000000000000044];  % mm
smiData.RigidTransform(1).angle = 3.1415926535897931;  % rad
smiData.RigidTransform(1).axis = [1 0 0];
smiData.RigidTransform(1).ID = "B[Link_0-1:-:Link_1-1]";

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(2).translation = [-84.999999999999488 -1.0942358130705543e-12 -17.500000000000007];  % mm
smiData.RigidTransform(2).angle = 0;  % rad
smiData.RigidTransform(2).axis = [0 0 0];
smiData.RigidTransform(2).ID = "F[Link_0-1:-:Link_1-1]";

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(3).translation = [0 0 0];  % mm
smiData.RigidTransform(3).angle = 2.0943951023931953;  % rad
smiData.RigidTransform(3).axis = [-0.57735026918962584 -0.57735026918962584 -0.57735026918962584];
smiData.RigidTransform(3).ID = "B[Link_0-1:-:]";

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(4).translation = [21.811290769468009 0 153.95071214934183];  % mm
smiData.RigidTransform(4).angle = 2.0943951023931953;  % rad
smiData.RigidTransform(4).axis = [-0.57735026918962584 -0.57735026918962584 -0.57735026918962584];
smiData.RigidTransform(4).ID = "F[Link_0-1:-:]";

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(5).translation = [85.615305239366251 0 -2.5000000000000022];  % mm
smiData.RigidTransform(5).angle = 0;  % rad
smiData.RigidTransform(5).axis = [0 0 0];
smiData.RigidTransform(5).ID = "B[Link_1-1:-:Link_2-1]";

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(6).translation = [-85.000000000003553 -1.1297629498585593e-12 -17.500000000000028];  % mm
smiData.RigidTransform(6).angle = 0;  % rad
smiData.RigidTransform(6).axis = [0 0 0];
smiData.RigidTransform(6).ID = "F[Link_1-1:-:Link_2-1]";

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(7).translation = [21.811290769468009 0 153.95071214934183];  % mm
smiData.RigidTransform(7).angle = 0;  % rad
smiData.RigidTransform(7).axis = [0 0 0];
smiData.RigidTransform(7).ID = "RootGround[Link_0-1]";


%============= Solid =============%
%Center of Mass (CoM) %Moments of Inertia (MoI) %Product of Inertia (PoI)

%Initialize the Solid structure array by filling in null values.
smiData.Solid(3).mass = 0.0;
smiData.Solid(3).CoM = [0.0 0.0 0.0];
smiData.Solid(3).MoI = [0.0 0.0 0.0];
smiData.Solid(3).PoI = [0.0 0.0 0.0];
smiData.Solid(3).color = [0.0 0.0 0.0];
smiData.Solid(3).opacity = 0.0;
smiData.Solid(3).ID = "";

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(1).mass = 0.1088638417314101;  % kg
smiData.Solid(1).CoM = [-11.512068656083706 -3.3426251486127385 0.33116710110164504];  % mm
smiData.Solid(1).MoI = [15.298375233457957 349.21279693773499 359.5802462709994];  % kg*mm^2
smiData.Solid(1).PoI = [-0.1205088622047561 2.9683176425404683 3.2516993739957165];  % kg*mm^2
smiData.Solid(1).color = [0.49803921568627452 0.49803921568627452 0.49803921568627452];
smiData.Solid(1).opacity = 1;
smiData.Solid(1).ID = "Link_1*:*Default";

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(2).mass = 0.37725282318667996;  % kg
smiData.Solid(2).CoM = [-0.82358756940461608 15.673836650852042 0.025577585043776236];  % mm
smiData.Solid(2).MoI = [603.18874226260857 945.54363096917575 614.52199711319179];  % kg*mm^2
smiData.Solid(2).PoI = [-0.81359110516600952 -0.0079455362461593477 12.454127745871194];  % kg*mm^2
smiData.Solid(2).color = [0.49803921568627452 0.49803921568627452 0.49803921568627452];
smiData.Solid(2).opacity = 1;
smiData.Solid(2).ID = "Link_0*:*Default";

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(3).mass = 0.092226717565734154;  % kg
smiData.Solid(3).CoM = [-17.230103270849757 -3.1388046808218801 0.4111742513206576];  % mm
smiData.Solid(3).MoI = [11.154390145615535 313.13631950127365 318.250368631122];  % kg*mm^2
smiData.Solid(3).PoI = [-0.11902753273230282 2.5699343833050059 3.0318072053885752];  % kg*mm^2
smiData.Solid(3).color = [0.49803921568627452 0.49803921568627452 0.49803921568627452];
smiData.Solid(3).opacity = 1;
smiData.Solid(3).ID = "Link_2*:*Default";


%============= Joint =============%
%X Revolute Primitive (Rx) %Y Revolute Primitive (Ry) %Z Revolute Primitive (Rz)
%X Prismatic Primitive (Px) %Y Prismatic Primitive (Py) %Z Prismatic Primitive (Pz) %Spherical Primitive (S)
%Constant Velocity Primitive (CV) %Lead Screw Primitive (LS)
%Position Target (Pos)

%Initialize the PlanarJoint structure array by filling in null values.
smiData.PlanarJoint(1).Rz.Pos = 0.0;
smiData.PlanarJoint(1).Px.Pos = 0.0;
smiData.PlanarJoint(1).Py.Pos = 0.0;
smiData.PlanarJoint(1).ID = "";

smiData.PlanarJoint(1).Rz.Pos = 0;  % deg
smiData.PlanarJoint(1).Px.Pos = 0;  % mm
smiData.PlanarJoint(1).Py.Pos = 0;  % mm
smiData.PlanarJoint(1).ID = "[Link_0-1:-:]";


%Initialize the RevoluteJoint structure array by filling in null values.
smiData.RevoluteJoint(2).Rz.Pos = 0.0;
smiData.RevoluteJoint(2).ID = "";

smiData.RevoluteJoint(1).Rz.Pos = -101.75897657536957;  % deg
smiData.RevoluteJoint(1).ID = "[Link_0-1:-:Link_1-1]";

smiData.RevoluteJoint(2).Rz.Pos = -93.975384654728146;  % deg
smiData.RevoluteJoint(2).ID = "[Link_1-1:-:Link_2-1]";

