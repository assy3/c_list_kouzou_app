#ifndef PERSONAL_DATA_FUNC_H
#define PERSONAL_DATA_FUNC_H

typedef struct tagPersonalData
{
	unsigned short usID;
	char cName[20];
	char cPhoneNo[15];
} PersonalData;


// Step1ä÷êî
BOOL SetPersonalData(PersonalData * data, unsigned short id, char * name, char * phoneNo);
BOOL WritePersonalDataArray(PersonalData * dataArray, unsigned short num, char * fileName);

// Step2ä÷êî
BOOL OpenPersonalData(char * fileName, unsigned short * numRecords);
BOOL ReadPersonalData(unsigned short pos, PersonalData * data);
BOOL ClosePersonalData(void);
BOOL GetPersonalData(PersonalData * data, unsigned short * id, char * name, char * phoneNo);

// Step3ä÷êî
BOOL SearchPersonalDataByID(unsigned short id, PersonalData * data);
BOOL SearchPersonalDataByName(char * name, PersonalData * data);


#endif /* OUYO_KADAI3_PDFUNC_H */