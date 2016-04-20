function varargout = GUI_Aquisicao(varargin)
% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @GUI_Aquisicao_OpeningFcn, ...
                   'gui_OutputFcn',  @GUI_Aquisicao_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end

function GUI_Aquisicao_OpeningFcn(hObject, eventdata, handles, varargin)

ylabel('Pressão (PSI)')
xlabel('Tempo (S)')
% Choose default command line output for GUI_Aquisicao
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% --- Outputs from this function are returned to the command line.
function varargout = GUI_Aquisicao_OutputFcn(hObject, eventdata, handles) 

% Get default command line output from handles structure
varargout{1} = handles.output;

% --- Executes on button press in iniciar.
function iniciar_Callback(hObject, eventdata, handles)
%x = 1:100;
%plot(x,x);

%Open serial comunication 
serialObject = serial('COM6');
set(serialObject, 'BaudRate', 19200);
% set(serialObject, 'Parity', 'none');
% set(serialObject, 'DataBits', 8);
% set(serialObject, 'StopBit', 1);
% set(serialObject, 'Timeout',10);
fopen(serialObject);


force = 0;
n = 1;
timeInterval = 0.01;
janela = 100;
global x;
x = 1;

N = serialObject.BytesAvailable();

while(N~=0) 
fread(serialObject,N);
N = serialObject.BytesAvailable();
end


while(x == 1)
%    time = cputime;
     
     fprintf(serialObject,'A %s',13);
     force(n) = 10*(fscanf(serialObject,'%f') - 176)/704; 
     %force(n) = rand; 
     i(n) = n*(timeInterval+0.02);% 33hz 
     
     ylabel('Force (Kg.f)')
     xlabel('Tempo (S)')
     if(n<janela+1)
     plot(i,force)
     else
     plot(i(n-janela:n),force(n-janela:n))
     end
     
%      resTime = cputime -time;
%      disp(resTime);
     
     pause(timeInterval);    
     %axis([0 10 0 100]);
     n = n+1;
      
end

fclose(serialObject);
delete(serialObject);
clear serialObject;
close(handles.GUI);

function sair_Callback(hObject, eventdata, handles)

global x;
x = 0;
% fclose(serialObject);
% delete(serialObject);
% clear serialObject;
% close(handles.GUI);
