#include "client.h"

client::client(int port,string ip):server_port(port),server_ip(ip){}
client::~client(){
    close(sock);
}
void client::run(){

    //����sockfd
    sock = socket(AF_INET,SOCK_STREAM, 0);

    //����sockaddr_in
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(server_port);  //�������˿�
    servaddr.sin_addr.s_addr = inet_addr(server_ip.c_str());  //������ip

    //���ӷ��������ɹ�����0�����󷵻�-1
    if (connect(sock, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        perror("connect");
        exit(1);
    }
    cout<<"���ӷ������ɹ�\n";

    //���������̺߳ͽ����߳�
    thread send_t(SendMsg,sock),recv_t(RecvMsg,sock);
    send_t.join();
    cout<<"�����߳��ѽ���\n";
    recv_t.join();
    cout<<"�����߳��ѽ���\n";
    return;
}
//ע�⣬ǰ�治�ü�static��
void client::SendMsg(int conn){
    char sendbuf[100];
    while (1)
    {
        memset(sendbuf, 0, sizeof(sendbuf));
        cin>>sendbuf;
        int ret=send(conn, sendbuf, strlen(sendbuf),0); //����
        //����exit���߶Զ˹ر�ʱ����
        if(strcmp(sendbuf,"exit")==0||ret<=0)
            break;
    }
}
//ע�⣬ǰ�治�ü�static��
void client::RecvMsg(int conn){
    //���ջ�����
    char buffer[1000];
    //���Ͻ�������
    while(1)
    {
        memset(buffer,0,sizeof(buffer));
        int len = recv(conn, buffer, sizeof(buffer),0);
        //recv����ֵС�ڵ���0���˳�
        if(len<=0)
            break;
        cout<<"�յ���������������Ϣ��"<<buffer<<endl;
    }
}