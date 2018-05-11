placas.pdf:voltaje.txt vecX.txt vecY.txt
	python grafica.py
	rm placas.x
	rm *.txt
voltaje.txt:placas.x
	./placas.x vo > voltaje.txt
vecX.txt:placas.x
	./placas.x vx > vecX.txt
vecY.txt:placas.x
	./placas.x > vecY.txt
placas.x:
	c++ placas.cpp -o placas.x
clean:
	rm *.pdf
