/* C-REST-Engine
*
* Copyright (c) 2017 VMware, Inc. All Rights Reserved. 
*
* This product is licensed to you under the Apache 2.0 license (the "License").
* You may not use this product except in compliance with the Apache 2.0 License.  
*
* This product may include a number of subcomponents with separate copyright 
* notices and license terms. Your use of these subcomponents is subject to the 
* terms and conditions of the subcomponent's license, as noted in the LICENSE file. 
*
*/

#define BAIL_ON_VMSOCK_ERROR(dwError)     \
    do {                                  \
        if (dwError) {                    \
            goto error;                   \
        }                                 \
    } while(0)

#ifdef WIN32
#define inet_pton(x, y, z) InetPtonA(x, y, z)
#endif
