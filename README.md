# 🌡️ Temperaturario v1.0

This repository contains the source code for the project **Temperaturario v1.0**. This project was submitted as homework during my third year at [I.T.I.S. Magistri Cumacini](https://www.magistricumacini.edu.it/) to my I.T. teacher.

## 🔰 Badges

![GitHub Repo stars](https://img.shields.io/github/stars/0tia0/Temperaturario?style=for-the-badge) ![GitHub forks](https://img.shields.io/github/forks/0tia0/Temperaturario?style=for-the-badge)  ![GitHub issues](https://img.shields.io/github/issues/0tia0/Temperaturario?style=for-the-badge) ![GitHub pull requests](https://img.shields.io/github/issues-pr/0tia0/Temperaturario?style=for-the-badge) ![GitHub contributors](https://img.shields.io/github/contributors/0tia0/Temperaturario?style=for-the-badge)

## 👾 Tech Stack

**I.D.E.:** [VSCode](https://code.visualstudio.com/)

**Language:** *C*

**Compiler:** [MinGW64](https://www.mingw-w64.org/) 
## 📋 Features

- **Randomicaly** generate some **temperature**
- Find **avarage, min and max** value of the days and weeks
- Cool **data** visualization inside a **table**

## ❓ FAQ

#### I'm waiting to receive any questions that should be placed here.

## 📸 Pictures

![day](/readme-img/1.png)

![table](/readme-img/2.png)

## ▶️ User use

### 📥 Installation

To install and try this project you need to:

- Download the most recent [release](https://github.com/0tia0/Temperaturario/releases) of this project.

### ⚙️ Run

To run the code of this project you need to:

- execute the file **main.exe**, if needed give the permession for execution

## 🖥️ Development

### 📥 Installation

I personally recommend to use [MinGW64](https://www.mingw-w64.org/) as the compiler for this project, and place his **bin** folder inside the windows **System Enviroment Variables** 

### ⚙️ Deployment

After you have installed and configured the compiler you can run this command in the root folder of this project:
```sh
gcc main.c -o main.exe
```
I reccomend to use the VSCode extension **code runner** to do all this stuff by just pressing a button. My personal configuration is:
```json
{
    "code-runner.runInTerminal": true, //true terminal //false output
    "code-runner.executorMap": {
            "c": "cd $dir && gcc main.c -o $fileNameWithoutExt && .\\$fileNameWithoutExt",
            "cpp": "cd $dir && g++ $fileName -o $fileNameWithoutExt -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32 -lsfml-graphics -lsfml-window -lsfml-system && .\\$fileNameWithoutExt ",
    },
}
```
All this should be placed inside the **settings.json** file from VSCode

## 📞 Support 

For support, you can create an [issue](https://github.com/0tia0/Temperaturario/issues) on this repository, as long as the project is supported

## 👨🏻‍💻 Authors

- Mattia Marelli: [@0tia0](https://www.github.com/0tia0)
