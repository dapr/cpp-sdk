libdapr.so : dapr/dapr.pb.o dapr/dapr.grpc.pb.o daprclient/daprclient.pb.o daprclient/daprclient.grpc.pb.o
	g++ -shared -Wl,-soname,libdapr.so.1 -o libdapr.1.0.0.so dapr/*.o daprclient/*.o

%.o : %.cc
	$(CXX) -c -fPIC -I./ $< -o $@

clean :
	rm -f dapr/*.o daprclient/*.o libdapr.so
