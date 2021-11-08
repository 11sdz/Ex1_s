CC= gcc
CFLAGS= -Wall
TARGETS1 = main.o advancedClassificationLoop.o basicClassification.o NumClass.h
TARGETS2 = main.o advancedClassificationRecursion.o basicClassification.o NumClass.h
OBJECTS_C = advancedClassificationLoop.c basicClassification.c NumClass.h

loops: libclassloops.a advancedClassificationLoop.o basicClassification.o	
recursives: libclassrec.a advancedClassificationRecursion.o basicClassification.o
recursived:	libclassrec.so advancedClassificationRecursion.o basicClassification.o
loopd: libclassloops.so advancedClassificationLoop.o basicClassification.o
mains: main.o libclassrec.a
	gcc -Wall -g -o mains main.o ./libclassrec.a -lm
maindloop: main.o libclassloops.so
	gcc -Wall -g -o maindloop main.o ./libclassloops.so -lm
maindrec: main.o libclassrec.so 
	gcc -Wall -g -o maindrec main.o ./libclassrec.so -lm
all: mains maindloop maindrec loops recursives recursived loopd libclassrec.so libclassrec.a libclassloops.so libclassloops.a

#---------------------------------------------------------------------------

main.o: main.c NumClass.h
	$(CC) $(CFLAGS) -c main.c -lm

advancedClassificationLoop.o: advancedClassificationLoop.c NumClass.h
	$(CC) $(CFLAGS) -c advancedClassificationLoop.c -lm

basicClassification.o: basicClassification.c NumClass.h
	$(CC) $(CFLAGS) -c basicClassification.c -lm

advancedClassificationRecursion.o: advancedClassificationRecursion.c NumClass.h
	$(CC) $(CFLAGS) -c advancedClassificationRecursion.c -lm

#----------------------------------------------------------------------------

libclassloops.a: $(TARGETS1)
	ar -rcs  libclassloops.a basicClassification.o advancedClassificationLoop.o 

libclassrec.a: $(TARGETS2)
	ar -rcs  libclassrec.a basicClassification.o advancedClassificationRecursion.o 

#----------------------------------------------------------------------------

libclassloops.so: basicClassification.o advancedClassificationLoop.o
	$(CC) $(CFLAGS) -shared -o libclassloops.so basicClassification.o advancedClassificationLoop.o -lm

libclassrec.so: basicClassification.o advancedClassificationLoop.o
	$(CC) $(CFLAGS) -shared -o libclassrec.so basicClassification.o advancedClassificationRecursion.o -lm


clean:
	rm -f *.o *.a *.so *.out maindrec mains maindloop