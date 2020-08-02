all: 
	c++ `Magick++-config --cxxflags --cppflags`  -o x29 main.cpp `Magick++-config --ldflags --libs` -llept -ltesseract
