libdapr.so : dapr/dapr.pb.o dapr/dapr.grpc.pb.o daprclient/daprclient.pb.o daprclient/daprclient.grpc.pb.o
	g++ -shared -Wl,-soname,libdapr.so.0 -o libdapr.0.2.0.so dapr/*.o daprclient/*.o

%.o : %.cc
	$(CXX) -c -fPIC -I./ $< -o $@

clean :
	rm -f dapr/*.o daprclient/*.o libdapr.so
