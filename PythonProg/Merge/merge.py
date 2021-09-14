from PyPDF2 import PdfFileReader, PdfFileWriter
'''
This program will merge pdfs depending on if the user
wants the entire pdfs withing a directory merged.
The other user is also given the option to add certain pages 
of a pdf.
'''
def merge_pdfs(paths, output):
    pdf_writer = PdfFileWriter()
    docs = len(paths)
    
    print("There are " + str(docs)+ " merge")
    prompt = input("Would you like to merge every page of the pdfs (Yes or No)?")
    
    if prompt == "Yes" or prompt == "yes":
        for path in paths:
            pdf_reader = PdfFileReader(path)
            for page in range(pdf_reader.getNumPages()):
            #Add each page to the writer object
                pdf_writer.addPage(pdf_reader.getPage(page))
    else:
        for path in paths:
        #need to add the pages into a list in order to add the ability 
        #for user to choose whatever pages he or she wants
            i = 1
            pdf_reader = PdfFileReader(path)
            print("You have " + str(pdf_reader.getNumPages()) + " pages to add")
            for page in range(pdf_reader.getNumPages()):
                print("Would you like to add page "+ str(i))
                rspns = input("Yes or No?")
                if rspns == "Yes" or rspns == "yes":
                    #Add the page to the writer object
                    pdf_writer.addPage(pdf_reader.getPage(page))
                else:
                    continue
                i+=1


    #Write out the merged PDF
    with open(output, 'wb') as out:
        pdf_writer.write(out)
        
class merge:
    def __init__(self):
        
        path1 = "C:\\Users\\a08lo\\Documents\\PythonProgs\\Merge\\LCWorkSummary.pdf"
        path2 = "C:\\Users\\a08lo\\Documents\\PythonProgs\\Merge\\LCWorkSummary(1).pdf"

        output =  PythonProgs\\Merge\\Output\\merged.pdf"

        paths = [path1, path2] 
        self.merging = merge_pdfs(paths, output)

myMerge = merge()
