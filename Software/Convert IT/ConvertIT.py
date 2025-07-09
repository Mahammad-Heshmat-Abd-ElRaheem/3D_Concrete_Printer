from tkinter import *
from tkinter import ttk
from tkinter import filedialog,messagebox

myframe = Tk()
myframe.title("G-Code Parser")
myframe.geometry("1920x1080")
myframe.iconbitmap('H:/Mechatronics/the_last/Graduation Project/Convert IT/Program_Icon.ico')

X=[]
Y=[]
Z=[]
G=[]
L=[]
H=[]
N=[]

global file
GCode_selected1=" "
opened_path=" "
includefile_selected = (r"G:\EMBEDEDD\ARM\ARM_Workspace\buzzer\include")
CheckbuttonVar = BooleanVar()
CheckbuttonVar.set(True)

def select_gcodefile():
      global GCode_selected1  
      GCode_selected1 = filedialog.askopenfilename(title="Select your G-Code file", filetypes=(("Text Files","*.txt"),))
      global opened_path
      opened_path = GCode_selected1
      myentry1.insert(0,GCode_selected1)
      GCode_selected1 = open(GCode_selected1,'r')
      Reading = GCode_selected1.read()
      
      myText.insert(END,Reading)
      GCode_selected1.close()
 
def select_includefile():
      CheckbuttonVar.set(False)
      global includefile_selected
      includefile_selected = filedialog.askdirectory(title="Select your include file")
      myentry2.insert(0,includefile_selected)
    
def Clear_screen():
      myText.delete(1.0,END)
      myentry1.delete(0,END) 
      global GCode_selected1
      GCode_selected1=" "
      global opened_path
      opened_path=" "
      MyList.clear()  

def Clear_file_entry():
      myentry2.delete(0,END)   
 
def Save_screen():
      global opened_path
      file_text = open(opened_path,"w")
      file_text.write(myText.get(1.0,END))
      file_text.close()
      messagebox.showinfo('Saving Info','Saved successfully')
    
     
def ConvertIT():
    if (opened_path==" ")or(GCode_selected1==" "):
        messagebox.showerror('Error','You did not choose file to convert')
    else:
          #global opened_path
          file = open( opened_path ,"r")
          global MyList
          MyList = file.readlines()
          file.close()
          for line in MyList:
              #now we should spliting each g-code by its speaces and put them in variable (line)
              line =line.split()
              #now line is a list has M commands & G commands & XYZ positions
              
              for code in line:
                  if code.startswith("G"):
                      code =code.replace("G","")
                      G.append(code)
                  if code.startswith("X"):
                      code =code.replace("X","")
                      X.append(code)
                  if code.startswith("Y"):
                      code =code.replace("Y","")
                      Y.append(code)
                  if code.startswith("Z"):
                      code =code.replace("Z","")
                      Z.append(code)
                  if code.startswith("L"):
                      code =code.replace("L","")
                      L.append(code)
                  if code.startswith("H"):
                      code =code.replace("H","")
                      H.append(code)
                  if code.startswith("N"):
                      code =code.replace("N","")
                      N.append(code)
          
          global includefile_selected 
          if (CheckbuttonVar.get())==True:
                global includefile_selected
                includefile_selected = (r"G:\EMBEDEDD\ARM\ARM_Workspace\buzzer\include")
          
                     
          MyGcode= open(includefile_selected+r"\G_Code.h","w")
          MyGcode.write("#ifndef  G_CODE_H\n")
          MyGcode.write("#define  G_CODE_H\n")
          MyGcode.write("u8 G_Commands[] = {0")
          for index in G :
              MyGcode.write(",")
              MyGcode.write(index)
          MyGcode.write("};\n")
      
          MyGcode.write("u8 X_Axis[] = {0")
          for index in X :
              MyGcode.write(",")
              MyGcode.write(index)
          MyGcode.write("};\n")
      
          MyGcode.write("u8 Y_Axis[] = {0")
          for index in Y :
              MyGcode.write(",")
              MyGcode.write(index)
          MyGcode.write("};\n")
      
          MyGcode.write("u8 Z_Axis[] = {0")
          for index in Z :
              MyGcode.write(",")
              MyGcode.write(index)
          MyGcode.write("};\n")
      
          MyGcode.write("u8 LAYERS_HEGHT[] = {0")
          for index in H :
              MyGcode.write(",")
              MyGcode.write(index)
          MyGcode.write("};\n")
      
          MyGcode.write("u8 NOF_LINES[] = {0")
          for index in N :
              MyGcode.write(",")
              MyGcode.write(index)
          MyGcode.write("};\n")
      
          MyGcode.write("u8 NOF_LAYERS = ")
          MyGcode.write(str(len(L)))
          MyGcode.write(";\n")
      
          MyGcode.write("#endif")
          MyGcode.close()
          G.clear()
          X.clear()
          Y.clear()
          Z.clear()
          L.clear()
          N.clear()
          H.clear()
          messagebox.showinfo('Converting Info','Converted successfully')      

# now designing two frames for widgetes 

fram1 = LabelFrame(myframe, text=" Select your G-Code.txt file ", width=920 ,font="Tahoma 15", fg="#003C43")
fram1.pack(side=LEFT, fill="both",padx=15,pady=15)

fram2 = LabelFrame(myframe, text=" Write your G-Code ", width=700 ,font="Tahoma 15", fg="#003C43")
fram2.pack(side=RIGHT, fill="both",padx=15,pady=15)

# designing the widgetes for the first frame
mylable1= Label(fram1, text="Choose your (Gcode.txt) location", font="Tahoma 20", fg="#003C43")
mylable1.place(x=435, y=80, anchor="center")

mybutton1 = Button(fram1, text="Select your G-Code.txt",width=20, fg="#FFFFFF" , bg="#003C43", font="Candara 15", command=select_gcodefile )
mybutton1.place(x=140, y=150, anchor="center")

myentry1 = Entry(fram1, width=41, font="Candara 20")
myentry1.place(x=578, y=150, anchor="center")

mylable2= Label(fram1, text="Choose your include file location", font="Tahoma 20", fg="#003C43")
mylable2.place(x=435, y=350, anchor="center")

mybutton2 = Button(fram1, text="Select your include file",width=20, fg="#FFFFFF" , bg="#003C43", font="Candara 15", command=select_includefile )
mybutton2.place(x=140, y=420, anchor="center")

myentry2 = Entry(fram1, width=41, font="Candara 20")
myentry2.place(x=578, y=420, anchor="center")

mycheckbutton1 = Checkbutton(fram1, text="Use the default location", font="Tahoma 15", fg="#003C43", variable=CheckbuttonVar, command=Clear_file_entry)
mycheckbutton1.place(x=400, y=460, anchor="center")

mybutton3 = Button(fram1, text="Convert IT",width=11 ,fg="#FFFFFF" , bg="#003C43", font="Candara 30", command=ConvertIT )
mybutton3.place(x=450, y=700, anchor="center")

mylable3= Label(fram1, text="Made by 3DCP Team", font="Tahoma 10", fg="#003C43")
mylable3.place(x=5, y=760, anchor="sw")
mylable3= Label(fram1, text=r"Under subervisor Dr\ Gamal Abd El Nasser", font="Tahoma 10", fg="#003C43")
mylable3.place(x=5, y=780, anchor="sw")
# designing the widgetes for the second frame

myText = Text(fram2, width=27 , height=17, fg="#003C43", font="Candara 27")
myText.place(x=275, y=400, anchor="center")

mybutton4 = Button(fram2, text="Clear",width=5 ,fg="#FFFFFF" , bg="#003C43", font="Candara 10", command=Clear_screen )
mybutton4.place(x=523, y=7, anchor="center")

mybutton4 = Button(fram2, text="Save",width=5 ,fg="#FFFFFF" , bg="#003C43", font="Candara 10", command=Save_screen )
mybutton4.place(x=470, y=7, anchor="center")

myframe.mainloop()