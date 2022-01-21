function [bh,ch,dh,Ish,signh,bv,cv,dv,Isv,signv] = fcn(I1,I2,I3,I4,I5,I6)

%I1:Intensidad del FT derecho
%I2:Intensidad del FT frente/derecho
%I3:Intensidad del FT inferior
%I4:Intensidad del FT superior
%I5:Intensidad del FT frente/izquierdo
%I6:Intensidad del FT izquierdo

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

%Plano Horizontal
if (((I1+1e-6)/(I6+1e-6) < 1.5) && ((I6+1e-6)/(I1+1e-6) < 1.5)) && ((I2>15)&&(I5>15)) % 0
    bh = 1.7875;
    ch = 11.77375;
    dh = 1.57625;
    Ish = (cosd(11.77375 + 1.7875*0) + 1.57625)/(cosd(11.77375 + 1.7875*0) + 1.57625+cosd(11.77375 + 1.7875*90) + 1.57625);
    signh = 0;
elseif I1 > I6 %0 - 90
    if (I1>I2)&&(((I6 > I2) && (I6 > I5)) || (((I2/(I5+1e-6) < 2.5) && (I5/(I2++1e-6) < 2.5)) && ((I2<10)||(I5<10)))) %90
        bh = 1;
        ch = 0;
        dh = 0;
        Ish = 0;
        signh = 1;
    else
        bh = 2.37125;
        ch = 2.827525;
        dh = 0.8898;
        Ish = I2/(I2+I1);
        signh = 1;
    end
elseif I6 > I1 %0 - -90
    if (I6>I5)&&(((I1 > I2) && (I1 > I5)) || (((I2/(I5+1e-6) < 2.5)&&(I5/(I2+1e-6) < 2.5) )&& ((I2<15)||(I5<15)))) %-90
        bh = 1;
        ch = 0;
        dh = 0;
        Ish = 0;
        signh = -1;
    else
        bh = 2.316;
        ch = -21.4075;
        dh = 0.861975;
        Ish = I5/(I5+I6);
        signh = -1;
    end
elseif (I1 <= 15)&&(I2 <= 5)&&(I5 <= 5)&&(I6 <= 15)%180
    bh = 1;
    ch = 0;
    dh = 0;
    Ish = 1;
    signh = 1;
else
    bh = 1;
    ch = 0;
    dh = 0;
    Ish = 1;
    signh = 0;
end


%Plano Vertical
if ((I3+1e-6)/(I4+1e-6) < 2) && ((I2+1e-6)/(I5+1e-6) < 2) % 0
    bv = 1.7875;
    cv = 11.77375;
    dv = 1.57625;
    Isv = (cosd(11.77375 + 1.7875*0) + 1.57625)/(cosd(11.77375 + 1.7875*0) + 1.57625+cosd(11.77375 + 1.7875*90) + 1.57625);
    signv = 0;
elseif (I3 + 5 < I4)%0-90
    if ((I3 > I5)) || ((I5/I3 < 2.5) && (I3<10)) %90
        bv = 1;
        cv = 0;
        dv = 0;
        Isv = 0;
        signv = 1;
    else
        bv = 1.7875;
        cv = 11.77375;
        dv = 1.57625;
        Isv = I5/(I4+I5);
        signv = 1;
    end
elseif (I4 + 5< I3) %0- -90
    if ((I4 > I2)) || ((I2/I4 < 2.5) && (I4<10)) %-90
        bv = 1;
        cv = 0;
        dv = 0;
        Isv = 0;
        signv = -1;
    else
        bv = 1.7875;
        cv = 11.77375;
        dv = 1.57625;
        Isv = I2/(I3+I2);
        signv = -1;
    end
else
    bv = 1.7875;
    cv = 11.77375;
    dv = 1.57625;
    Isv = (cosd(11.77375 + 1.7875*0) + 1.57625)/(cosd(11.77375 + 1.7875*0) + 1.57625+cosd(11.77375 + 1.7875*90) + 1.57625);
    signv = 0;
end
