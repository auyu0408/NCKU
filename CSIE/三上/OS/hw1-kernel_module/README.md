# OS2021_HW1
## Enviroment  
Linux version: 4.15.0-159-generic  
you can use githook to check your coding style, all script in script.example  
Make app and module separately, check Makefile.example   
## Setup  
Enter Makefile location:  
```bash=
cd module
```
1. Build and install module  
```bash=
make
```
2. Delete other file except source code  
```bash=
make clean
```
3. Compile module  
```bash=
make module
```
4. Compile app  
```bash=
make app
```
5. Install module  
```bash=
make ins
```
6. Remove module  
```bash=
make rm
```
7. Delete app  
```bash=
make del_app
```
8. Delete module  
```bash=
make del_module
```
## Useage  
- execute app
```bash=
./app
```