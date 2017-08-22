CC = icc
CXX = icpc
CFLAGS = -qopenmp -g
NO_OFFLOAD = -qno-offload


# the build target executables:
TARGET1 = pi_serial
TARGET2 = pi_omp
TARGET3 = pi_omp_mic

$(TARGET1):	$(TARGET1).cpp
	$(CXX)	$(NO_OFFLOAD)	$(TARGET1).cpp pi.h	-o	$(TARGET1)

$(TARGET2):	$(TARGET2).cpp
	$(CXX)	$(CFLAGS)	$(TARGET2).cpp pi.h	-o	$(TARGET2)

$(TARGET3):	$(TARGET3).cpp
	$(CXX)	$(CFLAGS)	$(TARGET3).cpp pi.h	-o	$(TARGET3)

# clean
clean:
	$(RM) $(TARGET1) $(TARGET2) $(TARGET3)
