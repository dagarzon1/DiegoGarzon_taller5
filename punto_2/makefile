cuerda.gif:cuerda.txt
	python animacion.py
	rm cuerda.txt
cuerda.txt:cuerda.x
	./cuerda.x > cuerda.txt
	rm cuerda.x
cuerda.x:
	c++ cuerda.cpp -o cuerda.x
clean:
	rm *.gif
