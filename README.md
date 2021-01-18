## NTUA - Electrical and Computer Engineering - Ypsilon Flow

This repository contains my personal academic projects while following the Computer Systems flow at the National Technical University of Athens. Details about each directory is given in the following sections.

### Microprocessors
_Basic AVR programming._  
Stack pointer handling, function generator, input and output exercises.

:bulb: Technologies used: ***AVR Assembly, C***

### Microprocessors Laboratory
_Various AVR applications._  
Stack pointer handling, interrupts, LCD and Keypad functionalities, DS1820 sensor application, Asynchronous Receiver/Transmitter communication, IoT applet.

:bulb: Technologies used: ***8085 Assembly, AVR Assembly, C***

### Operating Systems
_Unix system programming._  
Child process handling, signal communication, monitoring multiple file descriptors, pipe communication, socket communication.

:bulb: Technologies used: ***C*** _(sys/wait.h, sys/types.h, sys/select.h, sys/socket.h)_

### Multimedia Technology
_GUI applications on a flight management system and α well-known board game._  
Object-oriented approach, interface design, input handling, event handling, timelines, animations.

:bulb: Technologies used: ***Java*** _(JavaFX, SceneBuilder)_

### Image and Video Analysis and Technology

- **Image Cartoonification & Video Motion Detection**  
_Edge detection applications on images and videos._  
Color space selection, noise reduction, filtering, Laplacian/Canny/Marr-Hildreth edge detectors tested, Shi-Tomashi/Harris corner detectors tested, Lucas-Kanade motion prediction.

- **CIFAR-100 Image Classification**  
_CNN model optimizations on CIFAR-100 dataset with achieved accuracy ≈ 80%._  
Data preparation, various Convolutional Neural Network architectures tested, Dropout/EarlyStopping experimentation, Data Augmentantion, ResNet Transfer Learning.

:bulb: Technologies used: ***Python*** _(skimage, opencv, tensorflow)_

### Neural Networks and Intelligent Systems

- **Machine-Learning-Based Classification**  
_Classification techniques on [UCI](https://archive.ics.uci.edu/ml/index.php) datasets._  
Data preparation, class imbalance handling, standardization, Recursive Feature Elimination, Principal Component Analysis, Independent Component Analysis, KNeighbors/GaussianNB/MLP classifiers tested.

- **Recommender System & SOM Clustering**  
_Movie recommender system and movie clustering based on IMDb summaries._  
Data preparation, Term Frequency-Inverse Document Frequency represantation, cosine similarity, stemming, tokenizers, Self-Organizing-Maps, topological analysis.

- **CIFAR-100 Image Classification**  
_CNN model optimizations on CIFAR-100 dataset with achieved accuracy ≈ 75%._  
Data preparation, various Convolution Neural Network arhitectures tested, Data Augmentation, VGG19 Transfer Learning.

:bulb: Technologies used: ***Python*** _(imblearn, sklearn, tensorflow, somoclu)_

### Embedded System Design

- **Loop Transformations**  
_Techniques for improving energy consumption and execution time of functions._  
Loop Fusion, Unrolling Factor testing, Design Spce Exploration.

- **Dynamic Data Type Refinement**  
_Space exploration on different data structures in pursuit of data efficiency._  
Code preparation for Valgrind suite applications, Memory Accesses & Memory Footprint analysis.

- **ARM Assembly**  
_Applications written in ARM assembly and executed on QEMU simulator._  
Input/String manipulation, host-guest serial port communcation, ARM and C code linking.

- **High Level Synthesis**  
_HLS application and optimizations on MNIST GANs, run on ZYnq BOard._  
Hardware pragmas optimizations, various bit reconstruction accuracies tested.

- **Linux Kernel Cross-Compiling**  
_Cross-compiling a linux kernel for ARM architecture, simulated on QEMU._  

:bulb: Technologies used: ***C, Orio Tool, Valgrind*** _(Massif, Lackey)_***, ARM Assembly, QEMU, SDSoC***
