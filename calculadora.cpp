#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <ctime>
using namespace std;
int main () {
	setlocale (LC_ALL, "portuguese");
	
	time_t t;
	struct  tm * infoTempo;
	char data[10];
	char hora[10];
	
	time(&t);
	infoTempo = localtime(&t);
	
	strftime(data, 10, "%d/%m/%y", infoTempo); // armazena a data da execução
	strftime(hora, 10, "%I:%M", infoTempo); // armazena o horário da execução
	
	string nome, sobrenome, moeda [162] = {"Afegane (AFN)", "Ariary (MGA)", "Balboa (PAB)", "Baht (THB)", "Birr etíope (ETB)", "Bolivar Soberano Venezuelano (VES)", "Boliviano (BOB)", "Cedi (GHS)", "Colon da Costa Rica (CRC)", "Colon de El Salvador (SVC)", "Cordoba Ouro (NIO)", "Coroa dinamarquesa (DKK)", "Coroa islandesa (ISK)", "Coroa norueguesa (NOK)", "Coroa sueca (SEK)", "Coroa tcheca (CZK)", "Dalasi (GMD)","Dinar argelino (DZD)","Dinar sérvio (RSD)","Dinar do Bahrein (BHD)","Dinar iraquiano (IQD)","Dinar jordaniano (JOD)","Dinar do Kuwait (KWD)","Dinar da Líbia (LYD)","Dinar macedonio (MKD)","Dinar tunisiano (TND)","Direito especial de saque (XDR)","Dirham dos Emirados Árabes Unidos (AED)","Dirham marroquino (MAD)","Dobra São Tomé (STN)","Dólar australiano (AUD)","Dólar do Brunei (BND)","Dólar canadense (CAD)","Dólar do Caribe Oriental (XCD)","Dólar das Ilhas Cayman (KYD)","Dólar de Cingapura (SGD)","Dólar da Guiana (GYD)","Dólar da Namíbia (NAD)","Dólar das Ilhas Salomão (SBD)","Dólar do Suriname (SRD)","Dólar dos Estados Unidos (USD)","Dólar de Fiji (FJD)","Dólar de Hong Kong (HKD)","Dólar da Libéria (LRD)","Dólar da Nova Zelândia (NZD)","Dolar do Zimbabue (ZWL)","Dólar das Bahamas (BSD)","Dólar de Barbados (BBD)","Dólar do Belize (BZD)","Dólar de Bermuda (BMD)","Dólar jamaicano (JMD)","Dólar de Trindade e Tobago (TTD)","Dong (VND)","Dram (AMD)", "Escudo cabo-verdiano (CVE)", "Euro (EUR)", "Florim de Aruba (AWG)","Forint (HUF)","Franco CFA BCEAO (XOF)","Franco CFA BEAC (XAF)","Franco CFP (XPF)","Franco das Comores (KMF)","Franco congolês (CDF)","Franco suíço (CHF)","Franco do Burundi (BIF)","Franco do Djibuti (DJF)","Franco da Guiné (GNF)","Franco de Ruanda (RWF)","Florim (ANG)", "Gourde (HTG)", "Guarani (PYG)", "Grívnia (UAH)", "Iene (JPY)", "Kina (PGK)", "Kuna (HRK)", "Kwanza (AOA)", "Kwacha de Zambia (ZMW)", "Kwacha de Malavi (MWK)", "Kyat (MMK)", "Kip (LAK)", "Lari (GEL)","Lek (ALL)","Lempira (HNL)","Leone (SLL)","Leu da Moldávia (MDL)","Lev (BGN)","Libra de Gibraltar (GIP)","Libra de Santa Helena (SHP)","Libra Esterlina (GBP)","Libra Sul Sudanesa (SSP)","Libra egípcia (EGP)","Libra das Malvinas (FKP)","Libra libanesa (LBP)","Libra da Síria (SYP)","Lilangeni (SZL)","Lira turca (TRY)","Loti (LSL)","Leu romeno (RON)", "Manat do Azerbaijão (AZN)", "Marco conversível (BAM)", "Metical (MZN)", "Manat turcomano (TMT)", "Naira (NGN)", "Nakfa (ERN)", "Ngultrum (BTN)", "Nova libra sudanesa (SDG)", "Novo Dólar de Taiwan (TWD)", "Novo sol (PEN)", "Ouro (XAU)", "Ouguiya (MRU)", "Ouguiya (MRO)", "Paanga (TOP)","Pataca (MOP)","Peso argentino (ARS)","Peso chileno (CLP)","Peso colombiano (COP)","Peso cubano (CUP)","Peso filipino (PHP)","eso mexicano (MXN)","Peso dominicano (DOP)","Peso Uruguaio (UYU)","Pula (BWP)", "Quetzal guatemalteco (GTQ)", "Rand (ZAR)","Real (BRL)","Renminbi (CNY)","Renminbi Hong Kong (CNH)","Rial saudita (SAR)","Rial do Qatar (QAR)","Rial do Iêmen (YER)","Rial iraniano (IRR)","Rial Omã (OMR)","Riel (KHR)","Ringgit (MYR)","RUBLO BIELORRUSSO (BYN)","Rublo (RUB)","Rufia maldivense (MVR)","Rupia das Seychelles (SCR)","Rupia indiana (INR)","Rupia indonésia (IDR)","Rupia de Maurício (MUR)","Rupia nepalesa (NPR)","Rupia paquistanesa (PKR)","Rupia do Sri Lanka (LKR)", "Shekel (ILS)","Som (KGS)","Som Uzbeque (UZS)","Somoni (TJS)", "Taka (BDT)","Tala (WST)","Tenge (KZT)","Tugrik (MNT)", "Unidade monetária européia (XEU)","Unidade de fomento do chile (CLF)", "Vatu (VUV)", "Won sul coreano (KRW)","Won norte coreano (KPW)", "Xelim da Tanzânia (TZS)","Xelim queniano (KES)","Xelim somali (SOS)","Xelim de Uganda (UGX)", "Zloty (PLN)"}; // Todas as moedas utilizadas para câmbio em uma array tipo string
	int j, moeda_origem, moeda_destino; // j = responsável pela numeração das moedas / moeda_origem = responsável por identificar qual moeda de origem foi escolhida / moeda_destino = responsável por identificar qual moeda de destino foi escolhida
	float valor_converter, cin_conversao, valor_conversao, valor_conversao_taxa ,taxa; // valor_converter = valor inserido pelo usuário sobre o valor que deseja converter / cin_conversao = a taxa da moeda de origem para a de destino inserida pelo usuário (conforme obtido nos valores atuais)

	cout << "CASA DE CÂMBIO - MUITO DINHEIRO!\n\n" << "Calcuadora de Câmbio [Informações]: \n\n" << "* Informe sua moeda de origem e destino, assim como o valor a converter. \n" << "* A casa de câmbio Muito Dinheiro cobra uma taxa de 10% sobre cada operação de câmbio. \n" << "* É de extrema importância que informe a taxa de conversão de sua moeda de origem para a moeda de destino. \n" << "* A taxa deve estar atualizada conforme data de uso do programa. \n" << "* A taxa pode ser obtida através do Conversor de Moeda - Banco Central do Brasil ou pelo link https://www.bcb.gov.br/conversao. \n\n";
	system ("pause");
	system ("cls");
	
	cout << "Para iniciarmos, gostaria que informasse apenas seu primeiro e último nome: ";
	cin >> nome;
	cout << " ";
	cin >> sobrenome;
	
	inicio:
	
	cout << "As moedas estão separadas alfabeticamente, indique sua MOEDA DE ORIGEM: \n\n";
	j=1;

	for (int i=0; i<162; i++) {
		cout << j << ". " << moeda[i] << endl; // imprime todas as 162 moedas
		j++;
	}
	cout << endl;
	cin >> moeda_origem;
	if (moeda_origem < 0 or moeda_origem > 162) { // verifica se o usuário digitou algum número inválido
		system ("cls");
		cout << "Você digitou um número inválido, tente novamente!\n\n";
		system ("pause");
		system ("cls");
		goto inicio;
	}
	system ("cls");
	
	cout << "* Utilize ponto final para separar os centavos.\n\n" << "Insira o valor a converter de " << moeda[moeda_origem -1] << ": ";
	cin >> valor_converter;
	system ("cls");
	
	fim:

	cout << "As moedas estão separadas alfabeticamente, indique sua MOEDA DE DESTINO: \n\n";
	j=1;
	
	for (int i=0; i<162; i++) {
		cout << j << ". " << moeda[i] << endl;
		j++;
	}
	cout << endl;
	cin >> moeda_destino;
	if (moeda_destino < 1 or moeda_destino > 162) {
		system ("cls");
		cout << "Você digitou um número inválido, tente novamente!\n\n";
		system ("pause");
		system ("cls");
		goto fim;
	}
	system ("cls");
	
	cout << "* Utilize ponto final para separar os centavos.\n\n" << "Insira a taxa de conversão de " << moeda[moeda_origem -1] << " para " << moeda[moeda_destino -1] << ": ";
	cin >> cin_conversao;
	valor_conversao = valor_converter * cin_conversao; // multiplica o valor a converter com a taxa de conversão atual
	taxa = valor_conversao/10; // arquiva a taxa cobrada pela empresa Muito Dinheiro
	valor_conversao_taxa = valor_conversao - taxa; // valor convertido junto com os 10% de juros
	system ("cls");
	
	cout << "Muito obrigado(a) por escolher a casa de câmbio Muito Dinheiro como preferência!\n\n" << "Usuário: " << nome << " " << sobrenome << "\nData da operação: " << hora << " " << data << "\n\nConversão de: " << moeda[moeda_origem -1] << "\nValor a converter: " << valor_converter << "\n\nPara: " << moeda[moeda_destino -1] << "\nValor total sem taxas: " << valor_conversao << "\nResultado da conversão (com taxa de 10% aplicada): " << valor_conversao_taxa;
	
	return 0;
}
