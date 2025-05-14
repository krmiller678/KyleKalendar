![made-with-c++](https://img.shields.io/badge/Made_with-C%2B%2B-blue)

<!-- LOGO -->
<br />
<h1>
<p align="center">
  <img src="https://github.com/krmiller678/KyleKalendar/blob/main/KyleKalendarLogo.jpg" alt="Logo", width="50%", height ="auto">
  <br>
</h1>
  <p align="center">
    Super Speedy and Light C++ Planner App built with Qt
    <br />
    </p>
</p>
<p align="center">
  • <a href="#about-the-project">About The Project</a> •
  <a href="#quick-start">Quick Start</a> •
  <a href="#manually-build">Build</a> •
  <a href="#usage">How to Use</a> •
  <a href="#planned-features">Planned Features</a> •
  <a href="#acknowledgements">Acknowledgements</a> •
</p>  

<p align="center">
 
<img src="https://github.com/krmiller678/KyleKalendar/blob/main/KyleKalendar.png">
</p>                                                                                                                             
                                                                                                                                                      
## About The Project 
KyleKalendar is a weekly planner application with persistent memory that stores daily events and toDo objects in vectors that are automatically written back to .txt files upon program exit. It was inspired by my chalkboard that I have set up in my office to keep track 
of daily and weekly tasks, as well as important financial obligations and upcoming dates.  

The .txt files are read in and passed to the main program as vector files upon being read. Everything is packaged together in the release section.

<a id="quick-start"></a>
## Quick Start 🚀
All library files are dynamically linked and included in the zip directory below.  
[click me to download](https://github.com/krmiller678/KyleKalendar/releases/download/v1.0.0/RELEASE.v1.0.0.zip)

After downloading the release version, unzip the file and navigate to the `KyleKalendarQt.exe`. This executable will allow you to run the program.  

Navigate to <a href="#usage">How to Use</a> to get started using the app!

<a id="manually-build"></a>
## Manually Build 🛠️

Requirements:
- Qt 6.0.0 or later
- Cmake 3.16 or later
- C++17 or later

Clone from GitHub:
```
git clone https://github.com/krmiller678/KyleKalendar.git <my-directory>
```

Install Dependencies:  
- Visit the official [Qt Website](https://www.qt.io/download-qt-installer-oss) to select from a list of up to date installers for your OS.  
- Add Qt bin to your PATH variable. On Windows, the file is `C:\Qt\6.8.1\mingw_64\bin`
- Verify cmake version with `cmake --version` and install if needed [Cmake](https://cmake.org/download/)

Run CMake from cloned directory:  
```bash
mkdir build && cd build
cmake ..
make
./KyleKalendar
```

A note on deploying your own build: this [link](https://doc.qt.io/qt-6/windows-deployment.html) will take you through the Qt toolchain if you want to move your executable into its own directory and bundle it with dependencies for release.
If you do pursue this option, ensure you create blank _toDos_ and _events_ directories in the same directory as the executable. 

## Usage
### Input/Output
- **Single-Click** to engage with screen elements
- **Double-Click** to edit any of the user-defined fields
- **Return-Key** is reserved for adding a new item or completing an edit
- **Delete-Key** is reserved for deleting a currently selected item (when not editing or adding item)
- **Shift-Key** is reserved for striking through an item (when not editing or adding item)
### On Screen Buttons
- **PlusButton** to add a new item to that Day's agenda or the Financial, Important, or Weekly sections
- **\<DAY\> Button** to view the agenda items for that day  
- **Exit Button** will close out of program, exitting normally and writing back to txt files
- **SAVE Button** will write back to txt files  

### Screen Elements
- **DayOfWeek** will be _pushed_down_ when selected. Sunday is default day on launch
- **SelectedItem** will appear lightly highlighted with colored tab next to it

**NOTE:** You can wipe out the calendar at any point in time by navigating to the _toDos_ and _events_ directories and deleting the *.txt files

## Planned Features
- [X] Save button
- [ ] Progress tracker for projects/classes
- [ ] Auto load current day of week
- [ ] Add in autosave feature

## Acknowledgements
- Credit to the [Qt Community Forums](https://forum.qt.io/) for the great wealth of knowledge.
