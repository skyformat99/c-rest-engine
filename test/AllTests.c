#include <stdio.h>

#include "CuTest.h"

int  vmdns_syslog_level = 0;
int  vmdns_syslog = 0;
int  vmdns_debug = 0;

CuSuite* CuGetRestProtocolHeadSuite(void);
CuSuite* CuGetTestHTTPProtocolHeadSuite(void);
CuSuite* CuGetTestHttpUtilsExternalSuite(void);

void RunAllTests(void)
{
    CuString *output = CuStringNew();
    CuSuite* suite = CuSuiteNew();

    CuSuite* restProtocolHeadSuite = CuGetRestProtocolHeadSuite();
    CuSuiteAddSuite(suite, restProtocolHeadSuite);

    CuSuite* httpProtocolHeadSuite = CuGetTestHTTPProtocolHeadSuite();
    CuSuiteAddSuite(suite, httpProtocolHeadSuite);

    CuSuite* httpUtilsExternalSuite = CuGetTestHttpUtilsExternalSuite();
    CuSuiteAddSuite(suite, httpUtilsExternalSuite);

   /****** ADD MORE SUITES HERE ***********
   *  
   * CuSuite* utilSuite = CuGetUtilSuite();
   * CuSuiteAddSuite(suite, utilSuite);
   * CuSuiteDelete(utilSuite);
   *
   **************************************/

    CuSuiteRun(suite);
    CuSuiteSummary(suite, output);
    CuSuiteDetails(suite, output);


    printf("%s\n", output->buffer);

    CuSuiteDelete(suite);
    CuStringDelete(output);
}

int main(void)
{
    RunAllTests();
        return 0;
}