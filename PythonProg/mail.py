from docxtpl import DocxTemplate
from docx2pdf import convert
'''
This program allows the user to read the data from csv file
and copy the data into a word document. The word document will be
automatically and depending how rows there are in the csv file
that will be the number of word documents that will created.
Furthermore, each word document converted into a pdf file and saved 
in its own separate directory.
'''
#opens a csv file in order to gain access to its data
with open(r"C:\Users\a08lo\Documents\PythonProgs\LessonsCompleted.csv","r") as csvf:
    op = csvf.readlines()
print(type(op))

#ignore first item in list
#each excel line is treated as a list being separated by commas
#thus 0 is cell 'A', 1 with 'B' and 2 is 'C'
# the index starts at 1 because the first row has no useful info 
for i in op[1:]:
    first = i.split(",")[0]
    last = i.split(",")[1]
    LC = i.split(",")[2]

    #directory of word template
    doc = DocxTemplate(r"C:\Users\a08lo\Documents\PythonProgs\Mail\LPLetter.docx")
    #this dictionary holds the variable values that will be passed onto 
    #word document
    context = {'First': first, 'Last': last, 'LC': LC}
    #fills the word document with the dict values
    doc.render(context)
        
    filename = first + last + ".docx"
    path = "C:\\Users\\a08lo\\Documents\\PythonProgs\\Mail\\Output\\" + filename
    pathPDF = "C:\\Users\\a08lo\\Documents\\PythonProgs\\Mail\\PDF\\" + first + last + ".pdf"
    doc.save(f"C:\\Users\\a08lo\\Documents\\PythonProgs\\Mail\\Output\\{first}{last}.docx")
    #converts the word document to pdf and saves into a separate directory
    convert(path, pathPDF)  
