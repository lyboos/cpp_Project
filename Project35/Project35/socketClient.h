#pragma once
#ifdef __cplusplus
extern "C" {
#endif


//第一套接口
	//初始化环境
	int socketclient_init(void** handle);
	//发送信息
	int socketclient_send(void* handle, void* buf, int len);
	//接受信息
	int socketclient_recv(void* handle, void* buf, int len);
	//释放资源
	int socketclient_destroy(void* handle);

//第二套接口
		//初始化环境
	int socketclient_init2(void** handle);
	//发送信息
	int socketclient_send2(void* handle, void* buf, int len);
	//接受信息
	int socketclient_recv2(void* handle, void** buf, int len);
	//
	int socketclient_free2(void** buf); 
	//释放资源
	int socketclient_destroy2(void* handle);

#ifdef __cplusplus
}
#endif // 
