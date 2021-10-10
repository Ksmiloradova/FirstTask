# TheFirstTask

Формат командной строки\n
для генераци случайного транспорта:\n
    -n <transport number><output file> <log file>\n
для ввода из файла:\n
    -f <input file> <output file> <log file>\n

Формат ввода транспорта через файл\n

самолёт:\n
	1 <speed> <distance> <flightRange> <loadCapacity>\n
	speed: 500-900\n
	flightRange: 5000-20000\n
	loadCapacity: 16000-150000\n
поезд:\n
	1 <speed> <distance> <numberOfWagons>\n
	speed: 80-200\n
	numberOfWagons: 1-75\n
корабль:\n
	1 <speed> <distance> <displacement> <numberOfShipType>\n
	speed: 19-67\n
	displacement: 20000-500000\n
	numberOfShipType: 1-3