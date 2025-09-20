const CLOCK_REFRESH_INTERVAL = 2000;
const MIN_DOUBLE_DIGIT_NUMBER = 10;



/**
 * Adapted from
 */
function clock()
{
    const element = document.getElementById("clock");


    element.textContent = getTime();
    setInterval(() =>
        element.textContent = getTime(),
        CLOCK_REFRESH_INTERVAL
    );
}


/**
 * Get the current time.
 * // TODO: option for 12 hour time
 * @returns {string} Current time
 */
function getTime()
{
    const date = new Date();

    // Place a leading zero if the minute is a single digit, to ensure minutes are always two digits.
    if (date.getMinutes() < MIN_DOUBLE_DIGIT_NUMBER)
    {
        return `${date.getHours()}:${"0" + date.getMinutes()}`
    }
    else
    {
        return `${date.getHours()}:${date.getMinutes()}`
    }
}



function main()
{
    clock();
}





main();