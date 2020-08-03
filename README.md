![# Project X29 - Email Scraper](./media/banner.png)
#### Escraper : Fast Email Scraper from PDF and Photos in C++ (Python was too easy to do)

**If you like this project , show your support by donating or giving a 🌟 start to this repository**

### 🦋 What is this?
Escraper aka. Project X29 is an simple project to scrap email addresses from PDFs and Photos. Just Feed the Input File and get a output as a `.txt` file.

### 🦋 How to Use?
> ( Assume we have a input file called called `card.pdf` which is an business card an includes some email addresses which we want to extract.)

Execute this : 
```bash
$ escraper -p card.pdf
```
After this we will get a output file called `card.pdf.txt` which will contain all the email addresses present in `card.pdf`

### 🦋 Features:
* Extract emails from a pdf file:
```bash
$ escraper -p/--pdf FILENAME
```
* Extract emails from a pdf file:
```bash
$ escraper -i/--image FILENAME
```
* Choose custom output file:
```bash
$ escraper -o/--out OUTPUT
```

### 🔨 How to Build?
* Perquisites :
    * A C++ Compile
    ```bash
    sudo apt install build-essentials
    ```
    * ImageMagick Library
    ```bash
    sudo apt install graphicsmagick-libmagick-dev-compat
    ```
    * Tesseract OCR Library
    ```bash
    sudo apt install tesseract-ocr libtesseract-dev libleptonica-dev
    ```
    * Make
    ```bash
    sudo apt install make
    ```
* Git Clone or Download this repo
```bash
git clone https://github.com/bauripalash/escraper
```
* `cd` into the project folder
```bash
cd escraper
```
` Make
```bash
make
```
* Now you'll have a binary called escraper

---
If you like this project consider giving it a 🌟 star or donating. Follow me on socials [[Twitter]](https://twitter.com/bauripalash) | [[Facebook]](https://facebook.com/bauripalash) | [[Instagram]](https://instagram.com/bauripalash) | or even [[GitHub]](https://github.com/bauripalash)