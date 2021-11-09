%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% This software is licensed for use with Texas Instruments C28x
% family DSCs. This license was provided to you prior to installing
% the software.
% --------------------------------------------------------------------
% Copyright (C) 2010-2012 Texas Instruments, Incorporated.
% All Rights Reserved.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%% Clean workspace & enviroment 
clear all;
close all;
clc;

%% Fixed Point Variables Declarations
% NOTE: I dont need fixed point due to the C2000 core we use and its
% ability to handle floating point.

%Select numeric type,
T=numerictype('WordLength',32,'FractionLength',22);

%Specify math attributes to the fimath object
F=fimath('RoundMode','floor','OverflowMode','wrap');
F.ProductMode='SpecifyPrecision';
F.ProductWordLength=32;
F.ProductFractionLength=22;
F.SumMode='SpecifyPrecision';
F.SumWordLength=32;
F.SumFractionLength=22;

%specify fipref object, to display warning in cases of overflow and
%underflow
P=fipref;
P.LoggingMode='on';
P.NumericTypeDisplay='none';
P.FimathDisplay='none';

%% PLL Modelling starts from here

%Sampling Time = (1/fs)
% Note Ts is related to the frequency
% the DDSRFPLL would run, assuming 20Khz control loop for the inverter
Fs=20000;
Ts=1/Fs; 

Tfinal=0.2; % Total time the simulation is run for
t=0:Ts:Tfinal; % time vector
GridFreq=50; % nominal grid frequency
wn=2*pi*GridFreq; % nominal frequency in radians
fn=GridFreq;

%generate input signal
wu=2*pi*GridFreq;
theta=rem((t*2*pi*GridFreq),2*pi);
L=length(t);

%% generate input signal and create a fi object of it
%% CASE 1 : Phase Jump at the Mid Point

for n=1:floor(L/2)
Ua(n)=cos(theta(n));
Ub(n)=cos(theta(n)-2*pi/3);
Uc(n)=cos(theta(n)-4*pi/3);
end
for n=floor(L/2):L
Ua(n)=cos(theta(n)+1.5);
Ub(n)=cos(theta(n)-2*pi/3+1.5);
Uc(n)=cos(theta(n)-4*pi/3+1.5);
end
Ua_ideal=Ua;

%% CASE 2: Unbalanced Grid
% for n=1:floor(L)
% Ua(n)=cos(theta(n));
% Ub(n)=1.1*cos(theta(n)-2*pi/3);
% Uc(n)=cos(theta(n)-4*pi/3);
% end
% Ua_ideal=cos(theta);

%% CASE 3: voltage harmonics
% for n=1:floor(L)
% Ua(n)=cos(theta(n))+0.05*cos(5*theta(n));
% Ub(n)=cos(theta(n)-2*pi/3)+0.05*(cos(5*(theta(n)-2*pi/3)));
% Uc(n)=cos(theta(n)-4*pi/3)+0.05*(cos(5*(theta(n)-4*pi/3)));
% end
% Ua_ideal=cos(theta);

%% CASE 4: voltage dips and swells
% %
% for n=1:floor(L/2)
% Ua(n)=cos(theta(n));
% Ub(n)=cos(theta(n)-2*pi/3);
% Uc(n)=cos(theta(n)-4*pi/3);
% end
% for n=floor(L/2):L
% Ua(n)=0.7*cos(theta(n));
% Ub(n)=0.7*cos(theta(n)-2*pi/3);
% Uc(n)=0.7*cos(theta(n)-4*pi/3);
% end
% Ua_ideal=cos(theta);

%% Plot and check data

plot(t,Ua,t,Ub,t,Uc);

legend('Ua', 'Ub', 'Uc');

%% Export Data to a .c file
fid = fopen('data.c','wt');
fprintf(fid,'float Ua[] = { \n');
for i=1:length(Ua)
    fprintf(fid,'%.2f,\n',Ua(i));
end
    fprintf(fid,'};');
    
    fprintf(fid,'\n\n');
    
    fprintf(fid,'float Ub[] = { \n');
for i=1:length(Ub)
    fprintf(fid,'%.2f,\n',Ub(i));
end
    fprintf(fid,'};');
    
        fprintf(fid,'\n\n');
    
    fprintf(fid,'float Uc[] = { \n');
for i=1:length(Ub)
    fprintf(fid,'%.2f,\n',Uc(i));
end
    fprintf(fid,'};');
    
    fclose(fid);