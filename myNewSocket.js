var newSocket = new WebSocket('ws:localhost:6969');

function sendTo()
{   
    const information =
    {
        "firstName": document.getElementById('name').value,
        "ageValue": document.getElementById('age').value,
        "lastName": document.getElementById('lName').value,
        "birthday": document.getElementById('bDay').value
    }
    if(String(information.ageValue) !== "" && String(information.birthday) !== "" && String(information.firstName) !== "" && String(information.ageValue) !== "")
    {
        data = JSON.stringify(information);
        newSocket.send(data);
    }
}
