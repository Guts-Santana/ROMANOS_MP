#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "romanos.hpp"


TEST_CASE( "Numeros romanos - algarismos �nicos", "[romanos]" ) {
    REQUIRE( romanos_para_decimal("I") == 1 );
    
    REQUIRE( romanos_para_decimal("V") == 5 );

    REQUIRE( romanos_para_decimal("X") == 10 );

    REQUIRE( romanos_para_decimal("L") == 50 );

    REQUIRE( romanos_para_decimal("C") == 100 );

    REQUIRE( romanos_para_decimal("D") == 500 );

    REQUIRE( romanos_para_decimal("M") == 1000 );
}


TEST_CASE( "Numeros romanos - algarismos inv�lidos", "[romanos]" ) {
    REQUIRE( romanos_para_decimal("G") == -1 );
    
    REQUIRE( romanos_para_decimal("i") == -1 );

    REQUIRE( romanos_para_decimal("IA") == -1);

    REQUIRE( romanos_para_decimal("XXXIN") == -1);

    REQUIRE( romanos_para_decimal("MMCS") == -1);

    REQUIRE( romanos_para_decimal("AA") == -1);

    REQUIRE( romanos_para_decimal("xiv") == -1);

    REQUIRE( romanos_para_decimal("morra") == -1);

    REQUIRE( romanos_para_decimal("testando") == -1);

    REQUIRE( romanos_para_decimal("odeio") == -1);

    REQUIRE( romanos_para_decimal("POO") == -1);
}



    TEST_CASE( " Numeros romanos - sintaxe invalida", "[romanos]")
    {
    REQUIRE( romanos_para_decimal("IIX") == -1);

    REQUIRE( romanos_para_decimal("XIXI") == -1);

    REQUIRE( romanos_para_decimal("XMC") == -1);

    REQUIRE( romanos_para_decimal("XCM") == -1);

    REQUIRE( romanos_para_decimal("VVV") == -1);

    REQUIRE( romanos_para_decimal("LLL") == -1);

    REQUIRE( romanos_para_decimal("DDD") == -1);

    REQUIRE( romanos_para_decimal("LDL") == -1);

    REQUIRE( romanos_para_decimal("CMM") == -1);

    REQUIRE( romanos_para_decimal("MCDIIII") == -1);

    REQUIRE( romanos_para_decimal("MIXV") == -1);

    REQUIRE( romanos_para_decimal("MIC") == -1);

    REQUIRE( romanos_para_decimal("MCMC") == -1);

    REQUIRE( romanos_para_decimal("CDIVV") == -1);

    REQUIRE( romanos_para_decimal("DDI") == -1);

    REQUIRE( romanos_para_decimal("CIVI") == -1);

    REQUIRE( romanos_para_decimal("MIC") == -1);

    REQUIRE( romanos_para_decimal("MDCM") == -1);

    REQUIRE( romanos_para_decimal("IMI") == -1);

    REQUIRE( romanos_para_decimal("CIVX") == -1);

    REQUIRE( romanos_para_decimal("DCCCC") == -1);

    REQUIRE( romanos_para_decimal("CDID") == -1);

    REQUIRE( romanos_para_decimal("MIXC") == -1);

    REQUIRE( romanos_para_decimal("MLXVV") == -1);

    REQUIRE( romanos_para_decimal("CCD") == -1);

    REQUIRE( romanos_para_decimal("MMMM") == -1);
    
    REQUIRE( romanos_para_decimal("ICXV") == -1);

    REQUIRE( romanos_para_decimal("XLIXI") == -1);

    REQUIRE( romanos_para_decimal("CMIC") == -1);

    REQUIRE( romanos_para_decimal("CIMD") == -1);
    
    REQUIRE( romanos_para_decimal("LDVM") == -1);

    REQUIRE( romanos_para_decimal("MMCDD") == -1);

    REQUIRE( romanos_para_decimal("DDMC") == -1);

    REQUIRE( romanos_para_decimal("XCCXC") == -1);
}

    TEST_CASE( "numeros romanos - numeros validos", "[romanos]")
    {
        REQUIRE( romanos_para_decimal("CXVII") == 117);

        REQUIRE( romanos_para_decimal("LXXXI") == 81);

        REQUIRE( romanos_para_decimal("MCCXXXIV") == 1234);

        REQUIRE( romanos_para_decimal("CCLXV") == 265);

        REQUIRE( romanos_para_decimal("MCMXCV") == 1995);

        REQUIRE( romanos_para_decimal("XLIX") == 49);

        REQUIRE( romanos_para_decimal("DCLXVII") == 667);

        REQUIRE( romanos_para_decimal("CMXIII") == 913);

        REQUIRE( romanos_para_decimal("MMCDXLVI") == 2446);

        REQUIRE( romanos_para_decimal("MMM") == 3000);
    }
