function [bh,ch,dh,Ish,signh,bv,cv,dv,Isv,signv] = fcn(I1,I2,I3,I4,I5,I6)

%I1:Intensidad del FT derecho
%I2:Intensidad del FT frente/derecho
%I3:Intensidad del FT inferior
%I4:Intensidad del FT superior
%I5:Intensidad del FT frente/izquierdo
%I6:Intensidad del FT izquierdo

%U1:Valor umbral del FT derecho
%U2:Valor umbral del FT frente/derecho
%U3:Valor umbral del FT inferior
%U4:Valor umbral del FT superior
%U5:Valor umbral del FT frente/izquierdo
%U6:Valor umbral del FT izquierdo

%bh: Coeficiente b para el ángulo horizontal
%ch: Coeficiente c para el ángulo horizontal
%dh: Coeficiente d para el ángulo horizontal
%ISH: Relación de intensidades para el ángulo horizontal
%signh: Signo del ángulo del plano horizontal

%bv: Coeficiente b para el ángulo vertical
%cv: Coeficiente c para el ángulo vertical
%dv: Coeficiente d para el ángulo vertical
%ISV: Relación de intensidades para el ángulo vertical
%signv: Signo del ángulo del plano vertical




U1 = 10;
U2 = 10;
U3 = 10;
U4 = 10;
U5 = 10;
U6 = 10;
bh = 1.7875;
ch = 11.77375;
dh = 1.57625;
Ish = (cosd(11.77375 + 1.7875*0) + 1.57625)/(cosd(11.77375 + 1.7875*0) + 1.57625+cosd(11.77375 + 1.7875*90) + 1.57625);
signh = 0
bv = 1.7875;
cv = 11.77375;
dv = 1.57625;
Isv = (cosd(11.77375 + 1.7875*0) + 1.57625)/(cosd(11.77375 + 1.7875*0) + 1.57625+cosd(11.77375 + 1.7875*90) + 1.57625);
signv = 0
%Plano Horizontal
if (I1 <= U1) && (I6 <= U6) % Cero grados
    bh = 1.7875;
    ch = 11.77375;
    dh = 1.57625;
    Ish = (cosd(11.77375 + 1.7875*0) + 1.57625)/(cosd(11.77375 + 1.7875*0) + 1.57625+cosd(11.77375 + 1.7875*90) + 1.57625);
    signh = 0
elseif (I6 <= U6) %0-90
    bh = 1.7875;
    ch = 11.77375;
    dh = 1.57625;
    Ish = I2/(I2+I1);
    signh = 1;
elseif (I1 >= U1)&&(I2 <= U2)&&(I5 <= U5)&&(I6 <= U6) %90
    bh = 1;
    ch = 0;
    dh = 0;
    Ish = 0;
    signh = 1;
elseif (I1 <= U1) && (I6 >= U6) %0 - -90
    bh = 1.7875;
    ch = 11.77375;
    dh = 1.57625;
    Ish = I5/(I5+I6);
    signh = -1;    
elseif (I1 <= U1)&&(I2 <= U2)&&(I6 >= U6)&&(I5 <= U5)%-90
    bh = 1;
    ch = 0;
    dh = 0;
    Ish = 0;
    signh = -1;
elseif (I1 <= U1)&&(I2 <= U2)&&(I5 <= U5)&&(I6 <= U6)%180
    bh = 1;
    ch = 0;
    dh = 0;
    Ish = 1;
    signh = -1;
end

%Plano Vertical
if (I3 <= U3) && (I4 <= U4) %0
    bv = 1.7875;
    cv = 11.77375;
    dv = 1.57625;
    Isv = (cosd(11.77375 + 1.7875*0) + 1.57625)/(cosd(11.77375 + 1.7875*0) + 1.57625+cosd(11.77375 + 1.7875*90) + 1.57625);
    signv = 0;
elseif (I3 <= U3)&&(I4 >= U4)%0-90
    bv = 1.7875;
    cv = 11.77375;
    dv = 1.57625;
    Isv = I5/(I5+I6);
    signv = 1;
elseif (I4 >= U4)&&(I3 <= U3)&&(I5 <= U5)%90
    bv = 1;
    cv = 0;
    dv = 0;
    Isv = 0;
    signv = 1;
elseif (I4 <= U4) && (I3 >= U3) %0- -90
    bh = 1.7875;
    cv = 11.77375;
    dv = 1.57625;
    Isv = I2/(I3+I3);
    signv = -1;    
elseif (I3 >= U3)&&(I2 <= U2)&&(I4 <= U4)%-90
    bv = 1;
    cv = 0;
    dv = 0;
    Isv = 0;
    signv = -1;
end
