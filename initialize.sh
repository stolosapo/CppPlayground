BUILDDIR="build";
TESTDIR="test";
BINDIR="bin";
RES="resources";

cd src/
CDIRS=$(find -type d -printf '%d\t%P\n' | cut -f2-);
cd ..

cd "${RES}"
EXAMPLEFILES=$(find -type f -printf '%d\t%P\n' | cut -f2-);
cd ..

cd "${TESTDIR}"
TESTDIRS=$(find -type d -printf '%d\t%P\n' | cut -f2-);
cd ..

# Create build folder if is not exists
if [[ ! -d $BUILDDIR ]]; then
	mkdir $BUILDDIR;
fi

# Create bin folder if is not exists
if [[ ! -d $BINDIR ]]; then
	mkdir $BINDIR;
fi

for i in $CDIRS; do
	
	DIR="${BUILDDIR}/${i}";

	TESTER="${TESTDIR}/${i}";

	# Create each folder if is not exists
	if [[ ! -d $DIR ]]; then
		mkdir $DIR;
	fi

	# Create each folder in test if is not exists
	if [[ ! -d $TESTER ]]; then
		mkdir $TESTER;
	fi

	ln -sf src/${i}/*.* ${TESTER}/;

done

# Copy all files from resources to bin
for i in $EXAMPLEFILES; do
	
	FROM="${RES}/${i}";

	cp $FROM $BINDIR;

done

# Create extra test folders
for i in $TESTDIRS; do

	DIR="${BUILDDIR}/${i}";

	# Create each folder if is not exists
	if [[ ! -d $DIR ]]; then
		mkdir $DIR;
	fi

done