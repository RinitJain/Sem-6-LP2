def ask_question(question: str) -> str:
    response = input(question).strip().lower()
    return response

def analyze_market():
    print("Welcome to the Stock Market Expert System\n")

    price_trend = ask_question("What is the current price trend? (rising/falling/stable)")
    volume_trend = ask_question("What is the volume trend? (high/low)")
    moving_average = ask_question("Is there a moving average crossover? (yes/no)")
    sentiment = ask_question("What is the market sentiment? (positive/negative/neutral)")
    economic_indicator = ask_question("What is the current economic indicator? (strong/weak/neutral)")

    #Rule-based recommendations
    if price_trend == "rising" and volume_trend == "high" and sentiment == "positive" and economic_indicator == "strong":
        print("\nRecommendation: STRONG BUY (Bullish market with strong fundamentals)")
    elif price_trend == "falling" and volume_trend == "high" and sentiment == "negative" and economic_indicator == "weak":
        print("\nRecommendation: STRONG SELL (Bearish with weak fundamentals)")
    elif price_trend == "falling" and sentiment == "negative":
        print("\nRecommendation: SELL")
    elif price_trend == "rising" and (sentiment == "positive" or moving_average == "yes") and economic_indicator != "weak":
        print("\nRecommendation: BUY")
    elif price_trend == "stable" and sentiment == "neutral" and economic_indicator == "neutral":
        print("\nRecommendation: HOLD")
    else:
        print("\nRecommendation: HOLD or MONITOR (Insufficient clear signals)")

if __name__ == "__main__":
    analyze_market()