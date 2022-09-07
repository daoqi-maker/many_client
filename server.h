#ifndef SERVER_H
#define SERVER_H

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <iostream>
#include <thread>
#include <vector>
using namespace std;
class server{
    private:
        int server_port;//�������˿ں�
        int server_sockfd;//��Ϊlisten״̬���׽���������
        string server_ip;//������ip
        vector<bool> sock_arr;//���������׽���������
    public:
        server(int port,string ip);//���캯��
        ~server();//��������
        void run();//��������ʼ����
        static void RecvMsg(int conn);//���̹߳����ľ�̬����
};

#endif