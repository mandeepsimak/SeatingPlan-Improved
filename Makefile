CC = g++
CFLAG = -c  # Compilation Flag
OFLAG = -o  # O/p Flag

# Header files
HEADER = header.h file-names.h
READ_INPUT_HEADER = read-input.h $(HEADER)
EXPAND_ROLLNO_HEADER = expand-rollno.h $(READ_INPUT_HEADER)
ARRANGE_ROLLNO_HEADER = arrange-rollno.h $(EXPAND_ROLLNO_HEADER)
SUBJECTWISE_ROLLNO_HEADER = subject-wise-rollno.h $(ARRANGE_ROLLNO_HEADER)

# Linking of object files
INPUT = rollno.in rooms.in branchdetails.in # input files
READ_INPUT = read-input.o #Sread-input-main.o # read-input obj files
EXPAND_ROLLNO = $(READ_INPUT) expand-rollno.o #expand-rollno-main.o
ARRANGE_ROLLNO = $(EXPAND_ROLLNO) arrange-rollno.o arrange-rollno-main.o
SUBJECTWISE_ROLLNO = $(ARRANGE_ROLLNO) subject-wise-rollno.o subject-wise-rollno-main.o

# All Targets
all: arrange-rollno-run
#expand-rollno-run
#subject-wise-rollno-run
# arrange-rollno-run
#read-input-run

read-input.o: read-input.cc $(READ_INPUT_HEADER)
	$(CC) $(CFLAG) read-input.cc

read-input-main.o: read-input.o $(READ_INPUT_HEADER)
	$(CC) $(CFLAG) read-input-main.cpp

read-input: $(READ_INPUT)
	$(CC) $(OFLAG) read-input $(READ_INPUT)

read-input-run: $(INPUT) read-input
	./read-input
	
expand-rollno.o: expand-rollno.cc $(EXPAND_ROLLNO_HEADER)
	$(CC) $(CFLAG) expand-rollno.cc

expand-rollno-main.o: expand-rollno.o $(EXPAND_ROLLNO_HEADER)
	$(CC) $(CFLAG) expand-rollno-main.cpp

expand-rollno: $(EXPAND_ROLLNO)
	$(CC) $(OFLAG) expand-rollno $(EXPAND_ROLLNO)

expand-rollno-run: $(INPUT) expand-rollno
	./expand-rollno
	
arrange-rollno.o: arrange-rollno.cc $(ARRANGE_ROLLNO_HEADER)
	$(CC) $(CFLAG) arrange-rollno.cc

arrange-rollno-main.o: arrange-rollno.o $(ARRANGE_ROLLNO_HEADER)
	$(CC) $(CFLAG) arrange-rollno-main.cpp

arrange-rollno: $(ARRANGE_ROLLNO)
	$(CC) $(OFLAG) arrange-rollno $(ARRANGE_ROLLNO)

arrange-rollno-run: $(INPUT) arrange-rollno
	./arrange-rollno
	
subject-wise-rollno.o: subject-wise-rollno.cc $(SUBJECTWISE_ROLLNO_HEADER)
	$(CC) $(CFLAG) subject-wise-rollno.cc

subject-wise-rollno-main.o: subject-wise-rollno.o $(SUBJECTWISE_ROLLNO_HEADER)
	$(CC) $(CFLAG) subject-wise-rollno-main.cpp

subject-wise-rollno: $(SUBJECTWISE_ROLLNO)
	$(CC) $(OFLAG) subject-wise-rollno $(SUBJECTWISE_ROLLNO)

subject-wise-rollno-run: $(INPUT) subject-wise-rollno
	./subject-wise-rollno
	
clean:
	rm -f *.o *.out *.txt read-input expand-rollno arrange-rollno subject-wise-rollno 
	
#	*.html *.pdf *.csv report strategyValid
