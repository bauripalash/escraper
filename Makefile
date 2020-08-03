all: 
	c++ `Magick++-config --cxxflags --cppflags`  -o escraper main.cpp `Magick++-config --ldflags --libs` -llept -ltesseract
