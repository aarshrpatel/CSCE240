flags = -std=c++17 -Wall -I .

PixelShape.o : PixelShape.cc PixelShape.h
	g++ $(flags) -c $< -I .

# Failed constructor with "" argument test. GetName() returned  expected ?
testPixelShapeName : testPixelShapeName.cc PixelShape.o
	g++ $(flags) $^
	./a.out

# Failed constructor with '\n' argument test. GetPixel() returned expected *
testPixelShapePixel : testPixelShapePixel.cc PixelShape.o
	g++ $(flags) $^
	./a.out

RightIsosceles.o : RightIsosceles.cc RightIsosceles.h PixelShape.h
	g++ $(flags) -c $< -I .

testRightIsoscelesName : testRightIsoscelesName.cc RightIsosceles.o PixelShape.o
	g++ $(flags) $^
	./a.out

# Failed constructor with 1 as argument test. GetLeg() returned 1 expected 2
testRightIsoscelesLeg : testRightIsoscelesLeg.cc RightIsosceles.o PixelShape.o
	g++ $(flags) $^
	./a.out

testRightIsoscelesTimesEquals : testRightIsoscelesTimesEquals.cc RightIsosceles.o PixelShape.o
	g++ $(flags) $^
	./a.out

Rectangle.o : Rectangle.cc Rectangle.h PixelShape.h
	g++ $(flags) -c $< -I .

testRectangleName : testRectangleName.cc Rectangle.o PixelShape.o
	g++ $(flags) $^
	./a.out

# Failed constructor with one good and one bad argument test. GetLength() returned 0 (expected 1) and GetWidth() returned 9 (expected 4)
testRectangleSides : testRectangleSides.cc Rectangle.o PixelShape.o
	g++ $(flags) $^
	./a.out

testRectangleTimesEquals : testRectangleTimesEquals.cc Rectangle.o PixelShape.o
	g++ $(flags) $^
	./a.out

checkit : checkit.cc
	g++ $(flags) $^ -o $@

testVirtualPrints : testVirtualPrints.cc Rectangle.o RightIsosceles.o PixelShape.o
	g++ $(flags) $^ -o $@

testPrint1 : testVirtualPrints checkit
	./testVirtualPrints 2 true < sampleinput.txt > studentoutput1.txt
	rm testVirtualPrints
	./checkit 0

testPrint2 : testVirtualPrints checkit
	./testVirtualPrints 0.5 true < sampleinput.txt > studentoutput2.txt
	rm testVirtualPrints
	./checkit 1

testPrint3 : testVirtualPrints checkit
	./testVirtualPrints 2 false < sampleinput.txt > studentoutput3.txt
	rm testVirtualPrints
	./checkit 2

testPrint4 : testVirtualPrints checkit
	./testVirtualPrints 0.5 false < sampleinput.txt > studentoutput4.txt
	rm testVirtualPrints
	./checkit 3

clean :
	rm  *.o testVirtualPrints checkit studentoutput*.txt

