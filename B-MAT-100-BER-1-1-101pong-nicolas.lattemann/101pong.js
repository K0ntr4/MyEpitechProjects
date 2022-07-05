const show = require('./tools/show');
const calculate = require('./tools/calculate');

try {
    const PARAMS = process.argv.slice(2, Infinity).map((e) => (!isNaN(e) ? Number(e) : e));

    if (
        PARAMS[0] === '-h' || //
        PARAMS.length !== 7 ||
        PARAMS[6] < 0 ||
        String(PARAMS[6]) !== PARAMS[6].toFixed()
    ) {
        show.help();
        process.exit(84);
    }

    const invalidParams = PARAMS.slice(0, 7)
        .map((e, i) => (isNaN(e) ? i : 0))
        .filter((e) => e);

    if (invalidParams.length) {
        console.log('The first 7 parameters should be valid numbers.');
        process.exit(84);
    }

    const values = {
        pastPosition: {
            x: PARAMS[0],
            y: PARAMS[1],
            z: PARAMS[2],
        },
        currentPosition: {
            x: PARAMS[3],
            y: PARAMS[4],
            z: PARAMS[5],
        },
        n: PARAMS[6],
    };

    values.velocityVector = calculate.getVelocityVector(values);
    values.newPosition = calculate.getNewPosition(values);
    values.paddleHit = calculate.getPaddleHit(values);
    values.incidenceAngle = calculate.getIncidenceAngle(values);

    show.result(values);
    return 0;
} catch (err) {
    console.log(err);
    process.exit(84);
}
