#pragma once
#include "Transaction.h"

#define ZIA_FCT_PTR(N)	int (*N)(int status, ZIAApi::Transaction &, void *)
#define ZIA_FCT(N) int N(int status, ZIAApi::Transaction &transaction, void *param)

#define ZIA_ON_RECEIVE_CMD	0x1
#define ZIA_ON_RECEIVE_HEAD 0x10
#define ZIA_ON_RECEIVE_BODY 0x100
#define ZIA_MAKE_BODY		0x1000
#define ZIA_MAKE_HEAD		0x10000
#define ZIA_BEFORE_SEND		0x100000
#define ZIA_AFTER_SEND		0x1000000
#define ZIA_STATUT_DEFAULT	0x1111111
#define ZIA_WARNING			0x10000000
#define ZIA_ERROR			0x100000000
#define ZIA_FATAL_ERROR		0x1000000000

namespace ZIAApi
{
	struct ZIAModule
	{
		ZIA_FCT_PTR(loadModule);
		ZIA_FCT_PTR(onReceiveCommand);
		ZIA_FCT_PTR(onReceiveHead);
		ZIA_FCT_PTR(onReceiveBody);
		ZIA_FCT_PTR(makeResponseBody);
		ZIA_FCT_PTR(makeResponseHead);
		ZIA_FCT_PTR(beforeSendResponse);
		ZIA_FCT_PTR(afterSendResponse);
		ZIA_FCT_PTR(unloadModule);
	};
}
