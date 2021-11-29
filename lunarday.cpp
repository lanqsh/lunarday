#include <iostream>
#include <fstream>
#include <ctime>
#include <stdio.h>

using namespace std;

int runyue[]={
19 ,19 ,19 ,19 ,19 ,19 ,19 ,19 ,7  ,19 ,19 ,5  ,19 ,19 ,4  ,19 ,8  ,19 ,19 ,6  ,
19 ,19 ,4  ,19 ,10 ,19 ,19 ,6  ,19 ,19 ,5  ,19 ,19 ,3  ,19 ,8  ,19 ,19 ,5  ,19 ,
19 ,4  ,19 ,19 ,2  ,19 ,7  ,19 ,19 ,5  ,19 ,19 ,4  ,19 ,9  ,19 ,19 ,6  ,19 ,19 ,
4  ,19 ,19 ,2  ,19 ,6  ,19 ,19 ,5  ,19 ,19 ,3  ,19 ,11 ,19 ,19 ,6  ,19 ,19 ,5  ,
19 ,19 ,2  ,19 ,7  ,19 ,19 ,5  ,19 ,19 ,3  ,19 ,19 ,19 ,19 ,19 ,19 ,19 ,19 };
unsigned int lunar_table[][2]={
{7    ,8    },{36   ,71   },{66   ,102  },{95   ,133  },{124  ,164  },{154  ,195  },{184  ,226  },{213  ,257  },
{243  ,288  },{272  ,319  },{302  ,350  },{332  ,381  },{361  ,412  },{391  ,475  },{420  ,506  },{450  ,537  },
{479  ,568  },{508  ,599  },{538  ,630  },{567  ,661  },{597  ,692  },{626  ,723  },{656  ,754  },{686  ,785  },
{716  ,816  },{745  ,847  },{775  ,879  },{804  ,910  },{834  ,941  },{863  ,972  },{892  ,1003 },{922  ,1034 },
{951  ,1065 },{981  ,1096 },{1010 ,1127 },{1040 ,1158 },{1070 ,1189 },{1100 ,1220 },{1129 ,1283 },{1159 ,1314 },
{1188 ,1345 },{1218 ,1376 },{1247 ,1407 },{1276 ,1438 },{1306 ,1469 },{1335 ,1500 },{1364 ,1531 },{1394 ,1562 },
{1424 ,1593 },{1454 ,1624 },{1483 ,1687 },{1513 ,1718 },{1543 ,1749 },{1572 ,1780 },{1602 ,1811 },{1631 ,1842 },
{1660 ,1873 },{1690 ,1904 },{1719 ,1935 },{1748 ,1966 },{1778 ,1997 },{1808 ,2028 },{1837 ,2059 },{1867 ,2091 },
{1897 ,2122 },{1927 ,2153 },{1956 ,2184 },{1986 ,2215 },{2015 ,2246 },{2044 ,2277 },{2074 ,2308 },{2103 ,2339 },
{2132 ,2370 },{2162 ,2401 },{2191 ,2432 },{2221 ,2495 },{2251 ,2526 },{2281 ,2557 },{2310 ,2588 },{2340 ,2619 },
{2369 ,2650 },{2399 ,2681 },{2428 ,2712 },{2458 ,2743 },{2487 ,2774 },{2517 ,2805 },{2546 ,2836 },{2575 ,2867 },
{2605 ,2899 },{2635 ,2930 },{2664 ,2961 },{2694 ,2992 },{2724 ,3023 },{2753 ,3054 },{2783 ,3085 },{2812 ,3116 },
{2842 ,3147 },{2871 ,3178 },{2901 ,3209 },{2930 ,3240 },{2959 ,3303 },{2989 ,3334 },{3019 ,3365 },{3048 ,3396 },
{3078 ,3427 },{3107 ,3458 },{3137 ,3489 },{3167 ,3520 },{3196 ,3551 },{3226 ,3582 },{3255 ,3613 },{3285 ,3644 },
{3314 ,3707 },{3344 ,3738 },{3373 ,3769 },{3402 ,3800 },{3432 ,3831 },{3461 ,3862 },{3491 ,3893 },{3521 ,3924 },
{3550 ,3955 },{3580 ,3986 },{3610 ,4017 },{3639 ,4048 },{3669 ,4079 },{3698 ,4111 },{3728 ,4142 },{3757 ,4173 },
{3786 ,4204 },{3816 ,4235 },{3845 ,4266 },{3875 ,4297 },{3904 ,4328 },{3934 ,4359 },{3964 ,4390 },{3993 ,4421 },
{4023 ,4452 },{4053 ,4515 },{4082 ,4546 },{4112 ,4577 },{4141 ,4608 },{4170 ,4639 },{4200 ,4670 },{4229 ,4701 },
{4258 ,4732 },{4288 ,4763 },{4318 ,4794 },{4347 ,4825 },{4377 ,4856 },{4407 ,4919 },{4437 ,4950 },{4466 ,4981 },
{4496 ,5012 },{4525 ,5043 },{4554 ,5074 },{4584 ,5105 },{4613 ,5136 },{4642 ,5167 },{4672 ,5198 },{4702 ,5229 },
{4731 ,5260 },{4761 ,5291 },{4791 ,5323 },{4821 ,5354 },{4850 ,5385 },{4880 ,5416 },{4909 ,5447 },{4938 ,5478 },
{4968 ,5509 },{4997 ,5540 },{5026 ,5571 },{5056 ,5602 },{5085 ,5633 },{5115 ,5664 },{5145 ,5727 },{5175 ,5758 },
{5204 ,5789 },{5234 ,5820 },{5264 ,5851 },{5293 ,5882 },{5322 ,5913 },{5352 ,5944 },{5381 ,5975 },{5410 ,6006 },
{5440 ,6037 },{5469 ,6068 },{5499 ,6099 },{5529 ,6131 },{5558 ,6162 },{5588 ,6193 },{5618 ,6224 },{5647 ,6255 },
{5677 ,6286 },{5706 ,6317 },{5736 ,6348 },{5765 ,6379 },{5794 ,6410 },{5824 ,6441 },{5853 ,6472 },{5883 ,6535 },
{5912 ,6566 },{5942 ,6597 },{5972 ,6628 },{6001 ,6659 },{6031 ,6690 },{6061 ,6721 },{6090 ,6752 },{6120 ,6783 },
{6149 ,6814 },{6179 ,6845 },{6208 ,6876 },{6237 ,6939 },{6267 ,6970 },{6296 ,7001 },{6326 ,7032 },{6356 ,7063 },
{6385 ,7094 },{6415 ,7125 },{6444 ,7156 },{6474 ,7187 },{6504 ,7218 },{6533 ,7249 },{6563 ,7280 },{6592 ,7311 },
{6622 ,7343 },{6651 ,7374 },{6680 ,7405 },{6710 ,7436 },{6739 ,7467 },{6769 ,7498 },{6798 ,7529 },{6828 ,7560 },
{6858 ,7591 },{6887 ,7622 },{6917 ,7653 },{6947 ,7684 },{6976 ,7747 },{7006 ,7778 },{7035 ,7809 },{7064 ,7840 },
{7094 ,7871 },{7123 ,7902 },{7153 ,7933 },{7182 ,7964 },{7212 ,7995 },{7242 ,8026 },{7271 ,8057 },{7301 ,8088 },
{7331 ,8151 },{7360 ,8182 },{7390 ,8213 },{7419 ,8244 },{7448 ,8275 },{7478 ,8306 },{7507 ,8337 },{7536 ,8368 },
{7566 ,8399 },{7596 ,8430 },{7625 ,8461 },{7655 ,8492 },{7685 ,8523 },{7715 ,8555 },{7744 ,8586 },{7774 ,8617 },
{7803 ,8648 },{7832 ,8679 },{7862 ,8710 },{7891 ,8741 },{7920 ,8772 },{7950 ,8803 },{7979 ,8834 },{8009 ,8865 },
{8039 ,8896 },{8069 ,8959 },{8098 ,8990 },{8128 ,9021 },{8158 ,9052 },{8187 ,9083 },{8216 ,9114 },{8246 ,9145 },
{8275 ,9176 },{8304 ,9207 },{8334 ,9238 },{8363 ,9269 },{8393 ,9300 },{8423 ,9363 },{8452 ,9394 },{8482 ,9425 },
{8512 ,9456 },{8541 ,9487 },{8571 ,9518 },{8600 ,9549 },{8630 ,9580 },{8659 ,9611 },{8688 ,9642 },{8718 ,9673 },
{8747 ,9704 },{8777 ,9735 },{8806 ,9767 },{8836 ,9798 },{8866 ,9829 },{8896 ,9860 },{8925 ,9891 },{8955 ,9922 },
{8984 ,9953 },{9014 ,9984 },{9043 ,10015},{9072 ,10046},{9102 ,10077},{9131 ,10108},{9161 ,10171},{9190 ,10202},
{9220 ,10233},{9250 ,10264},{9279 ,10295},{9309 ,10326},{9339 ,10357},{9368 ,10388},{9398 ,10419},{9427 ,10450},
{9457 ,10481},{9486 ,10512},{9515 ,10543},{9545 ,10575},{9574 ,10606},{9604 ,10637},{9633 ,10668},{9663 ,10699},
{9693 ,10730},{9722 ,10761},{9752 ,10792},{9781 ,10823},{9811 ,10854},{9841 ,10885},{9870 ,10916},{9900 ,10979},
{9929 ,11010},{9958 ,11041},{9988 ,11072},{10017,11103},{10047,11134},{10076,11165},{10106,11196},{10136,11227},
{10165,11258},{10195,11289},{10225,11320},{10254,11383},{10284,11414},{10313,11445},{10342,11476},{10372,11507},
{10401,11538},{10430,11569},{10460,11600},{10490,11631},{10519,11662},{10549,11693},{10579,11724},{10609,11755},
{10638,11787},{10668,11818},{10697,11849},{10726,11880},{10756,11911},{10785,11942},{10814,11973},{10844,12004},
{10873,12035},{10903,12066},{10933,12097},{10963,12128},{10992,12191},{11022,12222},{11052,12253},{11081,12284},
{11110,12315},{11140,12346},{11169,12377},{11198,12408},{11228,12439},{11257,12470},{11287,12501},{11317,12532},
{11346,12595},{11376,12626},{11406,12657},{11436,12688},{11465,12719},{11494,12750},{11524,12781},{11553,12812},
{11582,12843},{11612,12874},{11641,12905},{11671,12936},{11700,12967},{11730,12999},{11760,13030},{11790,13061},
{11819,13092},{11849,13123},{11878,13154},{11908,13185},{11937,13216},{11966,13247},{11996,13278},{12025,13309},
{12055,13340},{12084,13403},{12114,13434},{12144,13465},{12173,13496},{12203,13527},{12233,13558},{12262,13589},
{12292,13620},{12321,13651},{12350,13682},{12380,13713},{12409,13744},{12439,13807},{12468,13838},{12498,13869},
{12527,13900},{12557,13931},{12587,13962},{12616,13993},{12646,14024},{12675,14055},{12705,14086},{12734,14117},
{12764,14148},{12793,14179},{12823,14211},{12852,14242},{12882,14273},{12911,14304},{12941,14335},{12970,14366},
{13000,14397},{13030,14428},{13059,14459},{13089,14490},{13119,14521},{13148,14552},{13177,14615},{13207,14646},
{13236,14677},{13266,14708},{13295,14739},{13325,14770},{13354,14801},{13384,14832},{13413,14863},{13443,14894},
{13473,14925},{13502,14956},{13532,14987},{13562,15019},{13591,15050},{13620,15081},{13650,15112},{13679,15143},
{13708,15174},{13738,15205},{13767,15236},{13797,15267},{13827,15298},{13857,15329},{13886,15360},{13916,15423},
{13946,15454},{13975,15485},{14004,15516},{14034,15547},{14063,15578},{14092,15609},{14122,15640},{14151,15671},
{14181,15702},{14211,15733},{14240,15764},{14270,15827},{14300,15858},{14330,15889},{14359,15920},{14388,15951},
{14418,15982},{14447,16013},{14476,16044},{14506,16075},{14535,16106},{14565,16137},{14594,16168},{14624,16199},
{14654,16231},{14684,16262},{14713,16293},{14743,16324},{14772,16355},{14802,16386},{14831,16417},{14860,16448},
{14890,16479},{14919,16510},{14949,16541},{14978,16572},{15008,16635},{15038,16666},{15067,16697},{15097,16728},
{15127,16759},{15156,16790},{15186,16821},{15215,16852},{15244,16883},{15274,16914},{15303,16945},{15333,16976},
{15362,17039},{15392,17070},{15421,17101},{15451,17132},{15481,17163},{15511,17194},{15540,17225},{15570,17256},
{15599,17287},{15628,17318},{15658,17349},{15687,17380},{15717,17411},{15746,17443},{15776,17474},{15805,17505},
{15835,17536},{15865,17567},{15894,17598},{15924,17629},{15953,17660},{15983,17691},{16012,17722},{16042,17753},
{16071,17784},{16101,17847},{16130,17878},{16160,17909},{16189,17940},{16219,17971},{16248,18002},{16278,18033},
{16307,18064},{16337,18095},{16367,18126},{16396,18157},{16426,18188},{16455,18219},{16485,18251},{16514,18282},
{16544,18313},{16573,18344},{16602,18375},{16632,18406},{16661,18437},{16691,18468},{16721,18499},{16751,18530},
{16780,18561},{16810,18592},{16839,18655},{16869,18686},{16898,18717},{16928,18748},{16957,18779},{16986,18810},
{17016,18841},{17045,18872},{17075,18903},{17105,18934},{17134,18965},{17164,18996},{17194,19059},{17223,19090},
{17253,19121},{17282,19152},{17312,19183},{17341,19214},{17370,19245},{17400,19276},{17429,19307},{17459,19338},
{17488,19369},{17518,19400},{17548,19431},{17578,19463},{17607,19494},{17637,19525},{17666,19556},{17696,19587},
{17725,19618},{17754,19649},{17784,19680},{17813,19711},{17843,19742},{17872,19773},{17902,19804},{17932,19867},
{17962,19898},{17991,19929},{18021,19960},{18050,19991},{18080,20022},{18109,20053},{18138,20084},{18168,20115},
{18197,20146},{18227,20177},{18256,20208},{18286,20271},{18316,20302},{18345,20333},{18375,20364},{18405,20395},
{18434,20426},{18464,20457},{18493,20488},{18522,20519},{18552,20550},{18581,20581},{18611,20612},{18640,20643},
{18670,20675},{18699,20706},{18729,20737},{18759,20768},{18788,20799},{18818,20830},{18847,20861},{18877,20892},
{18906,20923},{18936,20954},{18965,20985},{18995,21016},{19024,21079},{19054,21110},{19083,21141},{19113,21172},
{19142,21203},{19172,21234},{19202,21265},{19231,21296},{19261,21327},{19290,21358},{19320,21389},{19349,21420},
{19379,21483},{19408,21514},{19438,21545},{19467,21576},{19497,21607},{19526,21638},{19556,21669},{19585,21700},
{19615,21731},{19645,21762},{19674,21793},{19704,21824},{19733,21855},{19763,21887},{19792,21918},{19822,21949},
{19851,21980},{19880,22011},{19910,22042},{19939,22073},{19969,22104},{19999,22135},{20028,22166},{20058,22197},
{20088,22228},{20117,22291},{20147,22322},{20176,22353},{20206,22384},{20235,22415},{20264,22446},{20294,22477},
{20323,22508},{20353,22539},{20382,22570},{20412,22601},{20442,22632},{20472,22663},{20501,22695},{20531,22726},
{20560,22757},{20590,22788},{20619,22819},{20648,22850},{20678,22881},{20707,22912},{20737,22943},{20766,22974},
{20796,23005},{20826,23036},{20856,23099},{20885,23130},{20915,23161},{20944,23192},{20974,23223},{21003,23254},
{21032,23285},{21062,23316},{21091,23347},{21120,23378},{21150,23409},{21180,23440},{21210,23503},{21239,23534},
{21269,23565},{21299,23596},{21328,23627},{21358,23658},{21387,23689},{21416,23720},{21446,23751},{21475,23782},
{21504,23813},{21534,23844},{21564,23875},{21593,23907},{21623,23938},{21653,23969},{21682,24000},{21712,24031},
{21742,24062},{21771,24093},{21800,24124},{21830,24155},{21859,24186},{21888,24217},{21918,24248},{21948,24311},
{21977,24342},{22007,24373},{22036,24404},{22066,24435},{22096,24466},{22125,24497},{22155,24528},{22184,24559},
{22214,24590},{22243,24621},{22273,24652},{22302,24715},{22332,24746},{22361,24777},{22391,24808},{22420,24839},
{22450,24870},{22479,24901},{22509,24932},{22539,24963},{22568,24994},{22598,25025},{22627,25056},{22657,25087},
{22686,25119},{22716,25150},{22745,25181},{22774,25212},{22804,25243},{22833,25274},{22863,25305},{22893,25336},
{22922,25367},{22952,25398},{22982,25429},{23011,25460},{23041,25523},{23070,25554},{23100,25585},{23129,25616},
{23158,25647},{23188,25678},{23217,25709},{23247,25740},{23276,25771},{23306,25802},{23336,25833},{23366,25864},
{23395,25895},{23425,25927},{23454,25958},{23484,25989},{23513,26020},{23542,26051},{23572,26082},{23601,26113},
{23631,26144},{23660,26175},{23690,26206},{23720,26237},{23750,26268},{23779,26331},{23809,26362},{23838,26393},
{23868,26424},{23897,26455},{23926,26486},{23956,26517},{23985,26548},{24014,26579},{24044,26610},{24074,26641},
{24103,26672},{24133,26735},{24163,26766},{24193,26797},{24222,26828},{24252,26859},{24281,26890},{24310,26921},
{24340,26952},{24369,26983},{24398,27014},{24428,27045},{24458,27076},{24487,27107},{24517,27139},{24547,27170},
{24577,27201},{24606,27232},{24636,27263},{24665,27294},{24694,27325},{24724,27356},{24753,27387},{24782,27418},
{24812,27449},{24841,27480},{24871,27543},{24901,27574},{24931,27605},{24960,27636},{24990,27667},{25019,27698},
{25049,27729},{25078,27760},{25108,27791},{25137,27822},{25166,27853},{25196,27884},{25225,27947},{25255,27978},
{25285,28009},{25314,28040},{25344,28071},{25374,28102},{25403,28133},{25433,28164},{25462,28195},{25492,28226},
{25521,28257},{25551,28288},{25580,28319},{25609,28351},{25639,28382},{25668,28413},{25698,28444},{25728,28475},
{25757,28506},{25787,28537},{25817,28568},{25846,28599},{25876,28630},{25905,28661},{25935,28692},{25964,28755},
{25994,28786},{26023,28817},{26052,28848},{26082,28879},{26111,28910},{26141,28941},{26171,28972},{26200,29003},
{26230,29034},{26260,29065},{26289,29096},{26319,29159},{26348,29190},{26378,29221},{26407,29252},{26436,29283},
{26466,29314},{26495,29345},{26525,29376},{26554,29407},{26584,29438},{26614,29469},{26643,29500},{26673,29531},
{26703,29563},{26732,29594},{26762,29625},{26791,29656},{26820,29687},{26850,29718},{26879,29749},{26908,29780},
{26938,29811},{26968,29842},{26997,29873},{27027,29904},{27057,29967},{27087,29998},{27116,30029},{27146,30060},
{27175,30091},{27204,30122},{27234,30153},{27263,30184},{27292,30215},{27322,30246},{27351,30277},{27381,30308},
{27411,30339},{27441,30371},{27471,30402},{27500,30433},{27530,30464},{27559,30495},{27588,30526},{27618,30557},
{27647,30588},{27676,30619},{27706,30650},{27735,30681},{27765,30712},{27795,30775},{27825,30806},{27854,30837},
{27884,30868},{27914,30899},{27943,30930},{27972,30961},{28002,30992},{28031,31023},{28060,31054},{28090,31085},
{28119,31116},{28149,31179},{28179,31210},{28208,31241},{28238,31272},{28268,31303},{28297,31334},{28327,31365},
{28356,31396},{28386,31427},{28415,31458},{28444,31489},{28474,31520},{28503,31551},{28533,31583},{28562,31614},
{28592,31645},{28622,31676},{28651,31707},{28681,31738},{28711,31769},{28740,31800},{28770,31831},{28799,31862},
{28829,31893},{28858,31924},{28887,31987},{28917,32018},{28946,32049},{28976,32080},{29005,32111},{29035,32142},
{29065,32173},{29094,32204},{29124,32235},{29154,32266},{29183,32297},{29213,32328},{29242,32391},{29272,32422},
{29301,32453},{29330,32484},{29360,32515},{29389,32546},{29419,32577},{29448,32608},{29478,32639},{29508,32670},
{29537,32701},{29567,32732},{29597,33167}};
struct tm temptm ;
const int day_secs=60*60*24;

int encode(int yy,int mm,int dd,bool lunar=0)
{
    if(lunar)
    {
        if(mm>runyue[yy-1960]) mm++;
        else if(mm<0) mm=-mm+1;
        return (yy-1960)*404+(mm-1)*31+dd-3970;
    }
    temptm.tm_year=yy-1900;
    temptm.tm_mon=mm-1;
    temptm.tm_mday=dd;
    return (mktime(&temptm)+28800)/day_secs;
}

void decode(int code,int &yy,int &mm,int &dd,bool lunar=0)
{
    if(lunar)
    {
        code+=3970;
        yy=code/404;
        code=code%404;
        mm=code/31+1;
        dd=code%31;
        if(mm>runyue[yy])
        {
            mm--;
            if(mm==runyue[yy])
                mm=-mm;
        }
        yy+=1960;
    }
    else
    {
        time_t code2time=code*day_secs;
        temptm = *localtime(&code2time);
        yy=temptm.tm_year+1900;
        mm=temptm.tm_mon+1;
        dd=temptm.tm_mday;
    }
}

void make_lunar_data()
{
    fstream lin("lunar.txt");
    fstream run("run.txt");
    int yy,mm,dd,lyy,lmm,id,c=0;
    int ry[99]={0};
    while(run.good())
    {
        run>>lyy>>lmm;
        ry[lyy-1960]=lmm;
    }
    printf("int runyue[]={ \n");
    for (int i=0;i<99;i++)
    {
        if (ry[i]==0) ry[i]=19;
        printf("%-3d,",ry[i]);
        if((c++)%20==19) cout<<endl;
    }
    run.close();
    c=0;
    printf("};\nunsigned int lunar_table[][2]={ \n");
    while(lin.good())
    {
        lin>>yy>>mm>>dd>>lyy>>lmm;
        if(lmm>runyue[lyy-1960])
        {
            lmm--;
            if(lmm==runyue[lyy-1960])
                lmm=-lmm;
        }
        printf("{%-5d,%-5d},",encode(yy,mm,dd),encode(lyy,lmm,1,1));
        if((c++)%8==7) cout<<endl;
    }
    printf("}; ");
    lin.close();
}


int lookup_lunar_table(int col,int date)
{
    int raw=date/34;
    int delta=date-lunar_table[raw][col];
    for(; delta>=0; raw+= max(delta/34, 1))
        delta=date-lunar_table[raw][col];
    return raw-2;
}

void solar2lunar(int year, int month, int day, int &l_year, int &l_month, int &l_day)
{
    int date_id = encode(year,month,day);
    int raw=lookup_lunar_table(0,date_id);
    decode(lunar_table[raw][1]+(date_id-lunar_table[raw][0]),l_year, l_month, l_day,1);
}
void lunar2solar(int &year, int &month, int &day, int l_year, int l_month, int l_day)
{
    int date_id = encode(l_year, l_month, l_day,1);
    int raw=lookup_lunar_table(1,date_id);
    decode(lunar_table[raw][0]+(l_day-1),year,month,day);
}

int main(int argc, char **argv)
{
    int THIS_YEAR,THIS_MONTH,THIS_DAY;
    int lunar_year,lunar_month,lunar_day;

    THIS_YEAR = 2021;
    THIS_MONTH = 11;
    THIS_DAY = 26;
    
    solar2lunar(THIS_YEAR,THIS_MONTH,THIS_DAY, lunar_year,lunar_month ,lunar_day);
    cout << "solar:" << THIS_YEAR << '-' << THIS_MONTH << '-' << THIS_DAY 
        << ",lunar:" << lunar_year << '-' << lunar_month << '-' << lunar_day << endl;
    
    lunar2solar(THIS_YEAR,THIS_MONTH,THIS_DAY, lunar_year,lunar_month ,lunar_day);
    cout << "solar:" << THIS_YEAR << '-' << THIS_MONTH << '-' << THIS_DAY 
        << ",lunar:" << lunar_year << '-' << lunar_month << '-' << lunar_day << endl;
    
    return 0;
}

