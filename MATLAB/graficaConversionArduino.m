% Nombre del archivo de entrada
archivo = 'datos_convertidos.txt';

% Leer el archivo de entrada
datos = dlmread(archivo, '\t');

% Obtener el número de filas y columnas
[num_filas, ~] = size(datos);

% Calcular el vector de tiempo en segundos
tiempo = (0 : num_filas-1) / 480; % Se asume una frecuencia de muestreo de 480 muestras por segundo

% Crear una figura para la gráfica
figure;
hold on;

% Generar la gráfica para cada columna
for col = 1 : 6
    amplitud = datos(:, col);
    plot(tiempo, amplitud);
end

% Configurar el título y etiquetas de los ejes
title('Gráfica de Amplitud vs Tiempo');
xlabel('Tiempo (s)');
ylabel('Amplitud');

% Mostrar la leyenda para cada columna
legend('Columna 1', 'Columna 2', 'Columna 3', 'Columna 4', 'Columna 5', 'Columna 6');

% Mostrar la cuadrícula
grid on;

% Ajustar los ejes para que se vea toda la gráfica
axis tight;

% Mostrar la gráfica
hold off;
