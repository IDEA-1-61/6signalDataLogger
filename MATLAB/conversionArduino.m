% Nombre del archivo de entrada
archivo_entrada = 'datos.txt';

% Nombre del archivo de salida
archivo_salida = 'datos_convertidos.txt';

% Leer el archivo de entrada
datos = dlmread(archivo_entrada, '\t');

% Convertir los valores enteros a flotantes de 0 a 20 con 2 decimales
datos_convertidos = datos * (20.0 / 1023.0);
datos_convertidos = round(datos_convertidos, 2);

% Guardar los datos convertidos en un archivo de texto
dlmwrite(archivo_salida, datos_convertidos, 'delimiter', '\t', 'precision', '%.2f');

disp('Datos convertidos guardados en el archivo datos_convertidos.txt.');
