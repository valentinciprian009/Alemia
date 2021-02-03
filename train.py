import os
import glob
import shutil
import re

def create_dir(path):
    if not(os.path.isdir(path)):
        os.mkdir(path)

def preprocess_datas(src_dir, dest_dir):
    dir = os.listdir(dest_dir)
    if(len(dir)!=0):
        print("Files already exist")
        return

    for filename in glob.iglob(src_dir + '**/*.*', recursive=True):
        fields = filename.split("/")
        create_dir(dest_dir+"/"+fields[3])    
        create_dir(dest_dir+"/"+fields[3]+"/text")    
        create_dir(dest_dir+"/"+fields[3]+"/headers")    
        create_dir(dest_dir+"/"+fields[3]+"/sources")    
        create_dir(dest_dir+"/"+fields[3]+"/rest")
        extention = fields[-1].split(".")
        
        if(filename.endswith(".txt")):
            shutil.copy2(filename,dest_dir+fields[3]+"/text/"+fields[-1])
        else:
            if(filename.endswith(".h")):
                shutil.copy2(filename,dest_dir+fields[3]+"/headers/"+fields[-1])
            else:
                if(filename.endswith(".cpp")):
                    shutil.copy2(filename,dest_dir+fields[3]+"/sources/"+fields[-1])
                else:
                    shutil.copy2(filename,dest_dir+fields[3]+"/rest/"+fields[-1])

def get_regex_counts(filename,regex_pattern):
    counts=0
    for i, line in enumerate(open(filename, "r", encoding = "ISO-8859-1")):
        for match in re.finditer(regex_pattern, line):
            #print ('Found on line %s: %s' % (i+1, match.group()))
            counts+=1
    return counts


def create_csv(trainDir,outfilename):
    output = open(outfilename,"w")
    output.write("nr_crt,label,nr_Clase,nr_errors,nr_inheritance,nr_virtual,nr_static,")
    output.write("nr_global,nr_public,nr_private,nr_prodected,nr_define,nr_template,")
    output.write("nr_stl,nr_namespace,nr_enum,nr_struct,total_size,\n")
    nrCrt=0
    for std in students:
       
        local_dir = trainDir+std
        headers = [h for h in os.listdir(local_dir +"/headers/") if os.path.isfile(os.path.join(local_dir+"/headers/", h))]
        sources = [s for s in os.listdir(local_dir+"/sources/") if os.path.isfile(os.path.join(local_dir+"/sources/", s))]
        texts = [t for t in os.listdir(local_dir+"/text/") if os.path.isfile(os.path.join(local_dir+"/text/", t))]

        class_number = len(headers)
        total_size = class_number + len(sources) + len(texts)
        
        if not(os.path.isfile(trainDir+std+"/codying_style.txt")):
            command = "cpplint "+local_dir+"/sources/* >"+trainDir+std+"/codying_style.txt"
            os.system(command)
        
        with open(trainDir+std+"/codying_style.txt", 'r') as f:
            lines = f.read().splitlines()
            last_line = lines[-1]
        codying_errors = last_line.split(" ")[-1]
        
        #REGEX 
        inheritance_pattern = re.compile("([A-Z])\w+ : ([a-z]\w+)")
        virtual_pattern = re.compile("virtual ([a-z]\w+)")
        static_pattern =  re.compile("\W*(static)\W*")
        global_pattern =  re.compile("\W*(global)\W*")
        public_pattern = re.compile("\W*(public)\W*")
        private_pattern = re.compile("\W*(private)\W*")
        protected_pattern = re.compile("\W*(protected)\W*")
        define_pattern = re.compile("^#define*")

        template_pattern = re.compile("\W*(template)\W*")
        stl_pattern = re.compile("\W*(std)\W*")
        namespace_pattern = re.compile("\W*(namespace)\W*")
        comments_pattern = re.compile("\W*(//)\W*")
        enum_pattern = re.compile("\W*(enum)\W*")
        struct_pattern = re.compile("W*(stuct)\W*")

        inheritance_count = 0
        virtual_count = 0
        static_count = 0
        global_count = 0
        public_count = 0
        private_count = 0
        protected = 0
        define_count = 0

        template_count = 0
        stl_count = 0
        namespace_count = 0
        comments_count = 0
        enum_count = 0
        struct_count = 0

        for header in headers:

            inheritance_count += get_regex_counts(local_dir+"/headers/"+header,inheritance_pattern)
            virtual_count += get_regex_counts(local_dir+"/headers/"+header,virtual_pattern)
            static_count += get_regex_counts(local_dir+"/headers/"+header,static_pattern)
            global_count += get_regex_counts(local_dir+"/headers/"+header,global_pattern)
            public_count += get_regex_counts(local_dir+"/headers/"+header,public_pattern)
            private_count += get_regex_counts(local_dir+"/headers/"+header,private_pattern)
            protected += get_regex_counts(local_dir+"/headers/"+header, protected_pattern )
            define_count += get_regex_counts(local_dir+"/headers/"+header,define_pattern)
            template_count += get_regex_counts(local_dir+"/headers/"+header,template_pattern)
            stl_count += get_regex_counts(local_dir+"/headers/"+header,struct_pattern)
            namespace_count += get_regex_counts(local_dir+"/headers/"+header,namespace_pattern)
            comments_count += get_regex_counts(local_dir+"/headers/"+header,comments_pattern)
            enum_count += get_regex_counts(local_dir+"/headers/"+header,enum_pattern)
            struct_count += get_regex_counts(local_dir+"/headers/"+header,struct_pattern)

        to_Write= []
        to_Write.append(nrCrt)
        to_Write.append(std)
        to_Write.append(class_number)
        to_Write.append(codying_errors)
        to_Write.append(inheritance_count)
        to_Write.append(virtual_count)
        to_Write.append(static_count)
        to_Write.append(global_count)
        to_Write.append(public_count)
        to_Write.append(private_count)
        to_Write.append(protected)
        to_Write.append(define_count)
        to_Write.append(template_count)
        to_Write.append(stl_count)
        to_Write.append(namespace_count)
        to_Write.append(enum_count)
        to_Write.append(struct_count)
        to_Write.append(total_size)
           
        for w in to_Write:
            output.write(str(w)+",")
        output.write("\n")
        nrCrt+=1
    output.close()
    


trainDir = "./preprocess/train/"
testDir = "./preprocess/test/"
create_dir(trainDir)
create_dir(testDir)

preprocess_datas("./input_data/train/", trainDir)
preprocess_datas("./input_data/test/", testDir)


students = [d for d in os.listdir(trainDir) if os.path.isdir(os.path.join(trainDir, d))]
create_csv(trainDir,"./train.csv")

#print(get_regex_counts("./test.txt",re.compile("\W*(//)\W*")))    
