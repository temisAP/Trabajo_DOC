clc
close all
clear all
%% Definición de parametros
A = 1;
B = 1;
C = 1;
D = 1;
E = 1;
Angles = deg2rad([0,10,20,30,40,50,60,70,80,90,-10,-20,-30,-40,-50,-60,-70,-80,-90]');
AnglesD60 = deg2rad([0,10,20,30,40,50,60,70,80,90,-10,-20,-30,-40,-50,-60]');
D60 = [122,118,110,97,85,69,51,35,25,18,123,122,111,102,88,69]';
AnglesD50 = deg2rad([0,10,20,30,40,50,60,70,80,90,-10,-20,-30,-40,-50,-60,-70]');
D50 = [124,119,108,98,84,71,52,38,26,18,127,126,113,104,87,72,56]';
AnglesD40 = deg2rad([0,10,20,30,40,50,60,70,80,90,-10,-20,-30,-40,-50,-60,-70]');
D40 = [121,117,108,95,76,68,54,41,32,22,123,121,110,99,85,71,57]';
AnglesD30 = deg2rad([0,10,20,30,40,50,60,70,-10,-20,-30,-40,-50,-60,-70]');
D30 = [110,103,92,79,73,61,51,45,111,109,95,86,76,65,52]';
AnglesD15 = deg2rad([0,10,20,30,40,50,-10,-20,-30,-40]');
D15 = [57,54,52,49,45,39,55,50,47,38]';

figure(1)
hold on
plot(AnglesD60,D60,'.')
plot(AnglesD50,D50,'.')
plot(AnglesD40,D40,'.')
plot(AnglesD30,D30,'.')
plot(AnglesD15,D15,'.')

Angles = ([0,10,20,30,40,50,60,70,80,90,-10,-20,-30,-40,-50,-60,-70,-80,-90]');
AnglesD60bis = ([0,10,20,30,40,50,60,70,80,90,-10,-20,-30,-40,-50,-60,-70]');
D60bis = [88,85,85,77,70,59,47,34,23,15,90,88,85,77,62,47,34]';
AnglesD50bis = ([0,10,20,30,40,50,60,70,80,90,-10,-20,-30,-40,-50,-60,-70]');
D50bis = [92,91,90,81,73,62,49,36,27,18,93,92,88,79,62,50,37]';
AnglesD40bis = ([0,10,20,30,40,50,60,70,80,90,-10,-20,-30,-40,-50,-60,-70,-80]');
D40bis = [93,90,84,77,68,59,50,40,28,21,95,95,88,77,63,50,39,28]';
AnglesD30bis = ([0,10,20,30,40,50,60,70,80,-10,-20,-30,-40,-50,-60,-70]');
D30bis = [90,88,80,73,64,55,46,38,30,90,86,80,70,62,47,38]';
AnglesD15bis = ([0,10,20,30,40,50,60,-10,-20,-30,-40,-50]');
D15bis = [60,57,56,50,47,39,33,58,54,50,41,35]';


figure(12)
hold on
plot(AnglesD60bis,D60bis,'.')
plot(AnglesD50bis,D50bis,'.')
plot(AnglesD40bis,D40bis,'.')
plot(AnglesD30bis,D30bis,'.')
plot(AnglesD15bis,D15bis,'.')


figure(3)
hold on
plot(AnglesD60bis,D60bis,'.')
plot(AnglesD50bis,D50bis,'.')
plot(AnglesD40bis,D40bis,'.')
plot(AnglesD30bis,D30bis,'.')
plot(AnglesD15bis,D15bis,'.')
plot(AnglesD60,D60,'.')
plot(AnglesD50,D50,'.')
plot(AnglesD40,D40,'.')
plot(AnglesD30,D30,'.')
plot(AnglesD15,D15,'.')

angles60_plus_90 = [90,80,70,60,50,40,30,20]';
D60_plus_90 = [17,20,42,58,74,84,92,99];
% Funcion empleada
%% Parametros para el de 60
 a60 =       56.39;  %(53.62, 59.17)
 b60 =      -1.615;  %(-1.692, -1.537)
 c60 =      -9.925;  %(-11.34, -8.509)
 d60 =       1.205;  %(1.091, 1.32)
%% Parametros para el de 50
       a50 =       56.31;  %(53.34, 59.28)
       b50 =      -1.629;  %(-1.711, -1.547)
       c50 =      -10.52;  %(-12.04, -8.996)
       d50 =       1.241;  %(1.117, 1.365)
%% Parametros para el de 40
       a40 =       49.85;  %(47.25, 52.45)
       b40 =      -1.714;  %(-1.804, -1.624)
       c40 =      -11.29;  %(-13.15, -9.434)
       d40 =       1.456;  %(1.325, 1.588)
%% Parametros para el de 30
       a30 =        32.3;  %(29.46, 35.14)
       b30 =       2.192;  %(1.989, 2.396)
       c30 =       15.36;  %(11.76, 18.96)
       d30 =       2.403;  %(2.104, 2.701)
%% Parametros para el de 15
%% Parametros para el de 60bis
       a60bis =       49.06;  %(34.74, 63.37)
       b60bis =      -1.384;  %(-1.688, -1.08)
       c60bis =      -2.083;  %(-4.846, 0.6789)
       d60bis =      0.8622;  %(0.2941, 1.43)
%% Parametros para el de 50bis
       a50bis =       46.51;  %(37.15, 55.87)
       b50bis =       1.473;  %(1.236, 1.71)
       c50bis =       1.664;  %(-0.7561, 4.083)
       d50bis =       1.057;  %(0.6224, 1.492)
%% Parametros para el de 40bis
       a40bis =        39.9;  %(34.07, 45.73)
       b40bis =      -1.632;  %(-1.854, -1.409)
       c40bis =      -3.722;  %(-6.741, -0.7026)
       d40bis =       1.385;  %(1.017, 1.753)

%% Parametros para el de 30bis
       a30bis =       31.73;  %(28.68, 34.78)
       b30bis =      -1.859;  %(-2.029, -1.688)
       c30bis =      -4.769;  %(-7.024, -2.514)
       d30bis =       1.848;  %(1.562, 2.133)
%% Parametros para el de 15bis
%a = mean(abs([a30,a40,a50,a60]));
b = mean(abs([b40,b50,b60]));
c = mean(abs([c40,c50,c60]));
d = mean(abs([d40,d50,d60]));


bbis = mean(abs([b30bis,b40bis,b50bis,b60bis]));
cbis = mean(abs([c30bis,c40bis,c50bis,c60bis]));
dbis = mean(abs([d30bis,d40bis,d50bis,d60bis]));