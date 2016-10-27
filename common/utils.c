/*
 * Copyright © 2012-2015 VMware, Inc.  All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the ~@~\License~@~]); you may not
 * use this file except in compliance with the License.  You may obtain a copy
 * of the License at http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an ~@~\AS IS~@~] BASIS, without
 * warranties or conditions of any kind, EITHER EXPRESS OR IMPLIED.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 */

#include "includes.h"

uint32_t
VmRESTUtilsConvertInttoString(
    int                              num,
    char*                            str
    )
{
    uint32_t                         dwError = 0;
    if(str == NULL)
    {
        dwError = 1;
    }
    BAIL_ON_VMREST_ERROR(dwError);
    sprintf(str, "%d", num);

cleanup:
    return dwError;
error:
    goto cleanup;

}

char
VmRESTUtilsGetLastChar(
    char*                            src
    )
{
    char                             ret = '\0';
    char*                            temp = NULL;

    if (src == NULL || (strlen(src) > MAX_SERVER_PORT_LEN))
    {
        VMREST_LOG_DEBUG("VmRESTUtilsGetLastChar(): Invalid Params");
        return ret;
    }
    temp = src;
    while (*temp != '\0')
    {
        ret = *temp;
        temp++;
    }
    return ret;
}