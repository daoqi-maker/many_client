#ifndef CLIENT_H
#define CLIENT_H

#include "global.h"

class client{
    private:
        int server_port;//�������˿�
        string server_ip;//������ip
        int sock;//��������������ӵ��׽���������
    public:
        client(int port,string ip);
        ~client();
        void run();//�����ͻ��˷���
        static void SendMsg(int conn);//�����߳�
        static void RecvMsg(int conn);//�����߳�
};
#endif