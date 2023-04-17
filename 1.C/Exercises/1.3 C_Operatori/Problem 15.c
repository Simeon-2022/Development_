int nA; 
	int nB;
	int nY;
	int nX;
	printf("Enter first number: ");
	scanf("%d", &nA);
	printf("\n");
	printf("Enter second number: ");
	scanf(" %d", &nB);
	printf("\n");
	printf("Enter third number: ");
	scanf(" %d", &nY);
	printf("\n");
	printf("Enter forth number: ");
	scanf(" %d", &nX);
	printf("\n");

	if (nA == nB && nA < 0) {
		printf("&& Operator : Both conditions are true\n");
	}
	if ((nX > nY || nY != 0) || (nY < 0)) {
		printf("|| Operator : Only one condition is true\n");
	}
	if (!(nA > nB && nB != 0 && nB > 0)) {
		printf("! Operator : One of the expressions is false.\n");
	}
	else {
		printf("! Operator : Both conditions are true\n");
	}
