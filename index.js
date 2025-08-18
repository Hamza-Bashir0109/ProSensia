import OpenAI from "openai";

const openai = new OpenAI({
  apiKey: process.env.OPENAI_API_KEY,
  dangerouslyAllowBrowser: true
});

const weatherApiKey = "YOUR_OPENWEATHER_API_KEY"; 
let travellers = 1;
const travellersEl = document.getElementById("travellers");
document.getElementById("increase").addEventListener("click", () => {
  travellers++;
  travellersEl.textContent = travellers;
});
document.getElementById("decrease").addEventListener("click", () => {
  if (travellers > 1) travellers--;
  travellersEl.textContent = travellers;
});

document.getElementById("planTrip").addEventListener("click", async () => {
  const fromCity = document.getElementById("fromCity").value;
  const toCity = document.getElementById("toCity").value;
  const fromDate = document.getElementById("fromDate").value;
  const toDate = document.getElementById("toDate").value;
  const budget = document.getElementById("budget").value;
  const resultEl = document.getElementById("result");

  resultEl.innerHTML = "Planning your trip...";
  const weatherRes = await fetch(
    `https://api.openweathermap.org/data/2.5/weather?q=${toCity}&units=metric&appid=${weatherApiKey}`
  );
  const weatherData = await weatherRes.json();
  const weatherInfo = `Weather in ${toCity}: ${weatherData.weather[0].description}, ${weatherData.main.temp}°C`;
  const messages = [
    {
      role: "system",
      content: "You are an AI travel agent that suggests itineraries."
    },
    {
      role: "user",
      content: `Plan a trip for ${travellers} traveller(s).
From: ${fromCity}
To: ${toCity}
Dates: ${fromDate} to ${toDate}
Budget: $${budget}
Weather forecast: ${weatherInfo}`
    }
  ];

  const completion = await openai.chat.completions.create({
    model: "gpt-4o-mini",
    messages
  });

  resultEl.innerHTML = `<h3>Trip Plan:</h3>
    <p>${completion.choices[0].message.content}</p>
    <h4>${weatherInfo}</h4>`;
});
