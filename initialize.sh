BUILDDIR="build";
TESTDIR="test";
BINDIR="bin";
RES="resources";

cd src/
CDIRS=$(find -type d -printf '%d\t%P\n' | cut -f2-);
cd ..

cd "${RES}"
EXAMPLEFILES=$(find -type f -printf '%d\t%P\n' | cut -f2-);
RESDIRS=$(find -type d -printf '%d\t%P\n' | cut -f2-);
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


# Create resource folders into bin folder
for i in $RESDIRS; do

    DIR="${BINDIR}/${i}";

    # Create each folder if is not exists
	if [[ ! -d $DIR ]]; then
		mkdir $DIR;
	fi

    # Copy files from resource folder into bin folder
    cp ${RES}/${i}/* ${DIR}

done


# Create extra test folders
for i in $TESTDIRS; do

	DIR="${BUILDDIR}/${i}";

	# Create each folder if is not exists
	if [[ ! -d $DIR ]]; then
		mkdir $DIR;
	fi

done
