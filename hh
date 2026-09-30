```html
<!DOCTYPE html>
<html lang="ar" dir="rtl">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>مسابقة التحدي - 60 سؤال</title>

    <style>
        * {
            box-sizing: border-box;
            margin: 0;
            padding: 0;
        }

        body {
            font-family: Arial, Tahoma, sans-serif;
            min-height: 100vh;
            background: linear-gradient(135deg, #101828, #172554, #312e81);
            color: white;
            display: flex;
            justify-content: center;
            align-items: center;
            padding: 20px;
        }

        .game {
            width: 100%;
            max-width: 900px;
            background: rgba(255, 255, 255, 0.08);
            backdrop-filter: blur(15px);
            border: 1px solid rgba(255,255,255,0.15);
            border-radius: 25px;
            padding: 30px;
            box-shadow: 0 20px 60px rgba(0,0,0,0.4);
        }

        .screen {
            display: none;
        }

        .screen.active {
            display: block;
        }

        .start-screen {
            text-align: center;
        }

        .logo {
            font-size: 70px;
            margin-bottom: 15px;
        }

        h1 {
            font-size: 40px;
            margin-bottom: 15px;
        }

        .description {
            color: #cbd5e1;
            font-size: 18px;
            line-height: 1.8;
            margin-bottom: 30px;
        }

        .levels {
            display: grid;
            grid-template-columns: repeat(3, 1fr);
            gap: 15px;
            margin-bottom: 30px;
        }

        .level {
            padding: 20px;
            border-radius: 15px;
            background: rgba(255,255,255,0.08);
            border: 1px solid rgba(255,255,255,0.1);
        }

        .level span {
            font-size: 30px;
            display: block;
            margin-bottom: 10px;
        }

        .level h3 {
            margin-bottom: 8px;
        }

        .level p {
            color: #cbd5e1;
            font-size: 14px;
        }

        button {
            border: none;
            cursor: pointer;
            font-family: inherit;
            transition: 0.2s;
        }

        .start-btn,
        .next-btn,
        .restart-btn {
            background: linear-gradient(135deg, #6366f1, #8b5cf6);
            color: white;
            padding: 15px 35px;
            border-radius: 12px;
            font-size: 18px;
            font-weight: bold;
        }

        button:hover {
            transform: translateY(-2px);
            filter: brightness(1.1);
        }

        .top-bar {
            display: flex;
            justify-content: space-between;
            align-items: center;
            gap: 15px;
            margin-bottom: 20px;
            flex-wrap: wrap;
        }

        .info-box {
            background: rgba(255,255,255,0.08);
            padding: 12px 18px;
            border-radius: 12px;
        }

        .timer {
            color: #fbbf24;
            font-weight: bold;
        }

        .timer.danger {
            color: #ef4444;
            animation: pulse 0.7s infinite;
        }

        @keyframes pulse {
            50% {
                transform: scale(1.08);
            }
        }

        .progress-container {
            width: 100%;
            height: 10px;
            background: rgba(255,255,255,0.1);
            border-radius: 20px;
            overflow: hidden;
            margin-bottom: 30px;
        }

        .progress {
            height: 100%;
            width: 0%;
            background: linear-gradient(90deg, #22c55e, #06b6d4);
            transition: width 0.3s;
        }

        .question-number {
            color: #a5b4fc;
            font-size: 16px;
            margin-bottom: 12px;
        }

        .question {
            font-size: 28px;
            line-height: 1.5;
            margin-bottom: 25px;
        }

        .options {
            display: grid;
            grid-template-columns: 1fr 1fr;
            gap: 15px;
        }

        .option {
            background: rgba(255,255,255,0.08);
            color: white;
            border: 2px solid rgba(255,255,255,0.1);
            border-radius: 15px;
            padding: 18px;
            font-size: 17px;
            text-align: right;
        }

        .option:hover:not(:disabled) {
            border-color: #818cf8;
            background: rgba(99,102,241,0.2);
        }

        .option.correct {
            background: rgba(34,197,94,0.25);
            border-color: #22c55e;
        }

        .option.wrong {
            background: rgba(239,68,68,0.25);
            border-color: #ef4444;
        }

        .option:disabled {
            cursor: default;
        }

        .feedback {
            min-height: 30px;
            margin: 20px 0;
            font-size: 18px;
            font-weight: bold;
        }

        .next-container {
            text-align: center;
        }

        .next-btn {
            display: none;
        }

        .result {
            text-align: center;
        }

        .result-icon {
            font-size: 80px;
            margin-bottom: 15px;
        }

        .final-score {
            font-size: 50px;
            font-weight: bold;
            color: #fbbf24;
            margin: 20px 0;
        }

        .result-message {
            font-size: 22px;
            margin-bottom: 25px;
        }

        .stats {
            display: grid;
            grid-template-columns: repeat(3, 1fr);
            gap: 15px;
            margin-bottom: 30px;
        }

        .stat {
            background: rgba(255,255,255,0.08);
            border-radius: 15px;
            padding: 20px;
        }

        .stat-number {
            font-size: 30px;
            font-weight: bold;
            color: #93c5fd;
            display: block;
            margin-bottom: 5px;
        }

        .stat-label {
            color: #cbd5e1;
        }

        .difficulty {
            display: inline-block;
            padding: 6px 12px;
            border-radius: 20px;
            font-size: 14px;
            margin-bottom: 15px;
        }

        .easy {
            background: rgba(34,197,94,0.2);
            color: #86efac;
        }

        .medium {
            background: rgba(234,179,8,0.2);
            color: #fde047;
        }

        .hard {
            background: rgba(239,68,68,0.2);
            color: #fca5a5;
        }

        @media (max-width: 700px) {
            .game {
                padding: 20px;
            }

            h1 {
                font-size: 30px;
            }

            .levels {
                grid-template-columns: 1fr;
            }

            .options {
                grid-template-columns: 1fr;
            }

            .question {
                font-size: 22px;
            }

            .stats {
                grid-template-columns: 1fr;
            }
        }
    </style>
</head>

<body>

<div class="game">

    <!-- شاشة البداية -->
    <section id="startScreen" class="screen active start-screen">

        <div class="logo">🧠</div>

        <h1>مسابقة التحدي</h1>

        <p class="description">
            اختبر معلوماتك في 60 سؤالًا!
            <br>
            الأسئلة مقسمة إلى سهل ومتوسط وصعب.
            <br>
            حاول الحصول على أعلى نتيجة ممكنة.
        </p>

        <div class="levels">

            <div class="level">
                <span>🟢</span>
                <h3>سهل</h3>
                <p>20 سؤالًا</p>
            </div>

            <div class="level">
                <span>🟡</span>
                <h3>متوسط</h3>
                <p>20 سؤالًا</p>
            </div>

            <div class="level">
                <span>🔴</span>
                <h3>صعب</h3>
                <p>20 سؤالًا</p>
            </div>

        </div>

        <button class="start-btn" onclick="startGame()">
            🚀 ابدأ اللعبة
        </button>

    </section>


    <!-- شاشة اللعبة -->
    <section id="gameScreen" class="screen">

        <div class="top-bar">

            <div class="info-box">
                السؤال:
                <strong>
                    <span id="currentQuestion">1</span>/60
                </strong>
            </div>

            <div class="info-box">
                النقاط:
                <strong id="score">0</strong>
            </div>

            <div class="info-box timer">
                ⏱️
                <span id="timer">20</span>
                ثانية
            </div>

        </div>

        <div class="progress-container">
            <div id="progress" class="progress"></div>
        </div>

        <div id="difficulty" class="difficulty">
            سهل
        </div>

        <div class="question-number">
            السؤال رقم <span id="questionNumber">1</span>
        </div>

        <h2 id="question" class="question">
            السؤال هنا
        </h2>

        <div id="options" class="options"></div>

        <div id="feedback" class="feedback"></div>

        <div class="next-container">
            <button id="nextBtn" class="next-btn" onclick="nextQuestion()">
                السؤال التالي ➡️
            </button>
        </div>

    </section>


    <!-- شاشة النتيجة -->
    <section id="resultScreen" class="screen result">

        <div class="result-icon">
            🏆
        </div>

        <h1>انتهت المسابقة!</h1>

        <div class="final-score">
            <span id="finalScore">0</span> / 600
        </div>

        <div id="resultMessage" class="result-message">
            أحسنت!
        </div>

        <div class="stats">

            <div class="stat">
                <span id="correctAnswers" class="stat-number">0</span>
                <span class="stat-label">إجابات صحيحة</span>
            </div>

            <div class="stat">
                <span id="wrongAnswers" class="stat-number">0</span>
                <span class="stat-label">إجابات خاطئة</span>
            </div>

            <div class="stat">
                <span id="percentage" class="stat-number">0%</span>
                <span class="stat-label">النسبة</span>
            </div>

        </div>

        <button class="restart-btn" onclick="restartGame()">
            🔄 العب مرة أخرى
        </button>

    </section>

</div>


<script>

const questions = [

    // =========================
    // 🟢 المستوى السهل
    // =========================

    {
        question: "ما عاصمة فلسطين؟",
        options: ["القدس", "نابلس", "غزة", "الخليل"],
        answer: "القدس",
        level: "سهل",
        points: 5
    },

    {
        question: "كم عدد أيام الأسبوع؟",
        options: ["5", "6", "7", "8"],
        answer: "7",
        level: "سهل",
        points: 5
    },

    {
        question: "ما الكوكب المعروف بالكوكب الأحمر؟",
        options: ["الأرض", "المريخ", "المشتري", "الزهرة"],
        answer: "المريخ",
        level: "سهل",
        points: 5
    },

    {
        question: "كم يساوي 5 + 7؟",
        options: ["10", "11", "12", "13"],
        answer: "12",
        level: "سهل",
        points: 5
    },

    {
        question: "ما أكبر محيط على الأرض؟",
        options: ["الأطلسي", "الهندي", "المتجمد الشمالي", "الهادئ"],
        answer: "الهادئ",
        level: "سهل",
        points: 5
    },

    {
        question: "كم عدد أشهر السنة؟",
        options: ["10", "11", "12", "13"],
        answer: "12",
        level: "سهل",
        points: 5
    },

    {
        question: "ما الحيوان المعروف بأنه ملك الغابة؟",
        options: ["النمر", "الأسد", "الفيل", "الذئب"],
        answer: "الأسد",
        level: "سهل",
        points: 5
    },

    {
        question: "ما لون ناتج خلط الأزرق والأصفر؟",
        options: ["أخضر", "أحمر", "بنفسجي", "برتقالي"],
        answer: "أخضر",
        level: "سهل",
        points: 5
    },

    {
        question: "كم عدد أرجل العنكبوت؟",
        options: ["6", "7", "8", "10"],
        answer: "8",
        level: "سهل",
        points: 5
    },

    {
        question: "ما اللغة الرسمية في البرازيل؟",
        options: ["الإسبانية", "البرتغالية", "الإنجليزية", "الفرنسية"],
        answer: "البرتغالية",
        level: "سهل",
        points: 5
    },

    {
        question: "ما عاصمة فرنسا؟",
        options: ["مدريد", "روما", "باريس", "برلين"],
        answer: "باريس",
        level: "سهل",
        points: 5
    },

    {
        question: "كم يساوي 10 × 5؟",
        options: ["40", "50", "60", "55"],
        answer: "50",
        level: "سهل",
        points: 5
    },

    {
        question: "ما الغاز الذي يحتاجه الإنسان للتنفس؟",
        options: ["الأكسجين", "الهيدروجين", "ثاني أكسيد الكربون", "الهيليوم"],
        answer: "الأكسجين",
        level: "سهل",
        points: 5
    },

    {
        question: "أي حيوان يعطي الحليب؟",
        options: ["البقرة", "الأسد", "النسر", "الثعبان"],
        answer: "البقرة",
        level: "سهل",
        points: 5
    },

    {
        question: "ما أقرب كوكب إلى الشمس؟",
        options: ["الأرض", "الزهرة", "عطارد", "المريخ"],
        answer: "عطارد",
        level: "سهل",
        points: 5
    },

    {
        question: "كم ساعة في اليوم؟",
        options: ["12", "18", "24", "30"],
        answer: "24",
        level: "سهل",
        points: 5
    },

    {
        question: "ما عاصمة إيطاليا؟",
        options: ["روما", "ميلانو", "نابولي", "تورينو"],
        answer: "روما",
        level: "سهل",
        points: 5
    },

    {
        question: "ما اسم القمر الطبيعي للأرض؟",
        options: ["القمر", "أوروبا", "تيتان", "فوبوس"],
        answer: "القمر",
        level: "سهل",
        points: 5
    },

    {
        question: "كم يساوي 100 ÷ 10؟",
        options: ["5", "10", "20", "15"],
        answer: "10",
        level: "سهل",
        points: 5
    },

    {
        question: "أي من هذه حاسة من حواس الإنسان؟",
        options: ["التفكير", "اللمس", "النوم", "المشي"],
        answer: "اللمس",
        level: "سهل",
        points: 5
    },


    // =========================
    // 🟡 المستوى المتوسط
    // =========================

    {
        question: "ما أكبر قارة في العالم؟",
        options: ["أفريقيا", "أوروبا", "آسيا", "أستراليا"],
        answer: "آسيا",
        level: "متوسط",
        points: 10
    },

    {
        question: "ما العنصر الكيميائي الذي رمزه Fe؟",
        options: ["الحديد", "الفلور", "الفضة", "الذهب"],
        answer: "الحديد",
        level: "متوسط",
        points: 10
    },

    {
        question: "كم عدد عظام جسم الإنسان تقريبًا عند البالغ؟",
        options: ["106", "206", "306", "406"],
        answer: "206",
        level: "متوسط",
        points: 10
    },

    {
        question: "ما الكوكب الأكبر في المجموعة الشمسية؟",
        options: ["الأرض", "زحل", "المشتري", "نبتون"],
        answer: "المشتري",
        level: "متوسط",
        points: 10
    },

    {
        question: "ما وحدة قياس شدة التيار الكهربائي؟",
        options: ["فولت", "أمبير", "واط", "أوم"],
        answer: "أمبير",
        level: "متوسط",
        points: 10
    },

    {
        question: "ما عاصمة اليابان؟",
        options: ["أوساكا", "كيوتو", "طوكيو", "هيروشيما"],
        answer: "طوكيو",
        level: "متوسط",
        points: 10
    },

    {
        question: "ما ناتج 15²؟",
        options: ["125", "200", "225", "250"],
        answer: "225",
        level: "متوسط",
        points: 10
    },

    {
        question: "ما العضو المسؤول بشكل أساسي عن ضخ الدم؟",
        options: ["الرئة", "الكبد", "القلب", "الكلية"],
        answer: "القلب",
        level: "متوسط",
        points: 10
    },

    {
        question: "ما أسرع حيوان بري؟",
        options: ["الأسد", "الفهد", "الحصان", "الذئب"],
        answer: "الفهد",
        level: "متوسط",
        points: 10
    },

    {
        question: "ما اسم العملية التي تصنع فيها النباتات غذاءها؟",
        options: ["التنفس", "التبخر", "البناء الضوئي", "الهضم"],
        answer: "البناء الضوئي",
        level: "متوسط",
        points: 10
    },

    {
        question: "كم عدد الكواكب في المجموعة الشمسية؟",
        options: ["7", "8", "9", "10"],
        answer: "8",
        level: "متوسط",
        points: 10
    },

    {
        question: "ما عاصمة أستراليا؟",
        options: ["سيدني", "ملبورن", "كانبيرا", "بيرث"],
        answer: "كانبيرا",
        level: "متوسط",
        points: 10
    },

    {
        question: "أي معدن يُستخدم بشكل واسع في صناعة الأسلاك الكهربائية؟",
        options: ["النحاس", "الحديد", "الرصاص", "الزنك"],
        answer: "النحاس",
        level: "متوسط",
        points: 10
    },

    {
        question: "ما أكبر عضو في جسم الإنسان؟",
        options: ["القلب", "الجلد", "الكبد", "الرئة"],
        answer: "الجلد",
        level: "متوسط",
        points: 10
    },

    {
        question: "ما اسم العلم الذي يدرس الكائنات الحية؟",
        options: ["الفيزياء", "الكيمياء", "الأحياء", "الفلك"],
        answer: "الأحياء",
        level: "متوسط",
        points: 10
    },

    {
        question: "كم ضلعًا للمثلث؟",
        options: ["2", "3", "4", "5"],
        answer: "3",
        level: "متوسط",
        points: 10
    },

    {
        question: "ما عاصمة ألمانيا؟",
        options: ["برلين", "ميونخ", "هامبورغ", "فرانكفورت"],
        answer: "برلين",
        level: "متوسط",
        points: 10
    },

    {
        question: "ما وحدة قياس الطاقة في النظام الدولي؟",
        options: ["نيوتن", "جول", "باسكال", "أمبير"],
        answer: "جول",
        level: "متوسط",
        points: 10
    },

    {
        question: "ما اسم المجرة التي توجد فيها الأرض؟",
        options: ["أندروميدا", "درب التبانة", "المثلث", "ماجلان"],
        answer: "درب التبانة",
        level: "متوسط",
        points: 10
    },

    {
        question: "أي جزء من النبات يمتص الماء من التربة؟",
        options: ["الأوراق", "الساق", "الجذور", "الزهرة"],
        answer: "الجذور",
        level: "متوسط",
        points: 10
    },


    // =========================
    // 🔴 المستوى الصعب
    // =========================

    {
        question: "ما العنصر الذي يحمل الرمز Au؟",
        options: ["الفضة", "الذهب", "النحاس", "الألومنيوم"],
        answer: "الذهب",
        level: "صعب",
        points: 15
    },

    {
        question: "ما سرعة الضوء تقريبًا في الفراغ؟",
        options: ["30 ألف كم/ث", "300 ألف كم/ث", "3 ملايين كم/ث", "3 آلاف كم/ث"],
        answer: "300 ألف كم/ث",
        level: "صعب",
        points: 15
    },

    {
        question: "من وضع قوانين الحركة الثلاثة؟",
        options: ["أينشتاين", "نيوتن", "غاليليو", "داروين"],
        answer: "نيوتن",
        level: "صعب",
        points: 15
    },

    {
        question: "ما أصغر عدد أولي؟",
        options: ["0", "1", "2", "3"],
        answer: "2",
        level: "صعب",
        points: 15
    },

    {
        question: "ما اسم القوة التي تجذب الأجسام نحو الأرض؟",
        options: ["الاحتكاك", "الجاذبية", "المغناطيسية", "الطفو"],
        answer: "الجاذبية",
        level: "صعب",
        points: 15
    },

    {
        question: "ما الكوكب الذي يمتلك أشهر نظام حلقات واضح؟",
        options: ["المريخ", "الأرض", "زحل", "عطارد"],
        answer: "زحل",
        level: "صعب",
        points: 15
    },

    {
        question: "ما الرمز الكيميائي للصوديوم؟",
        options: ["So", "S", "Na", "Sd"],
        answer: "Na",
        level: "صعب",
        points: 15
    },

    {
        question: "ما اسم تحول المادة من الحالة الصلبة إلى الغازية مباشرة؟",
        options: ["التكاثف", "الانصهار", "التسامي", "التبخر"],
        answer: "التسامي",
        level: "صعب",
        points: 15
    },

    {
        question: "ما العدد الذي إذا ضربته في نفسه يعطي 144؟",
        options: ["10", "11", "12", "14"],
        answer: "12",
        level: "صعب",
        points: 15
    },

    {
        question: "ما الجهاز المستخدم لقياس الزلازل؟",
        options: ["البارومتر", "السيزموجراف", "الترمومتر", "الهيجرومتر"],
        answer: "السيزموجراف",
        level: "صعب",
        points: 15
    },

    {
        question: "ما اسم أقرب نجم إلى الأرض بعد الشمس؟",
        options: ["سيريوس", "بروكسيما قنطورس", "فيغا", "منكب الجوزاء"],
        answer: "بروكسيما قنطورس",
        level: "صعب",
        points: 15
    },

    {
        question: "ما وحدة قياس المقاومة الكهربائية؟",
        options: ["أوم", "فولت", "أمبير", "واط"],
        answer: "أوم",
        level: "صعب",
        points: 15
    },

    {
        question: "أي كوكب يدور حول نفسه في اتجاه معاكس لمعظم الكواكب؟",
        options: ["الزهرة", "المريخ", "المشتري", "نبتون"],
        answer: "الزهرة",
        level: "صعب",
        points: 15
    },

    {
        question: "ما اسم العملية التي تتحول فيها الخلية إلى خليتين متماثلتين تقريبًا؟",
        options: ["الانقسام المتساوي", "البناء الضوئي", "الإخصاب", "التنفس"],
        answer: "الانقسام المتساوي",
        level: "صعب",
        points: 15
    },

    {
        question: "إذا كان محيط مربع 40 سم، فما طول ضلعه؟",
        options: ["5 سم", "10 سم", "15 سم", "20 سم"],
        answer: "10 سم",
        level: "صعب",
        points: 15
    },

    {
        question: "ما العدد الأولي التالي بعد 29؟",
        options: ["30", "31", "32", "33"],
        answer: "31",
        level: "صعب",
        points: 15
    },

    {
        question: "ما اسم العلم الذي يدرس النجوم والكواكب والمجرات؟",
        options: ["الجيولوجيا", "الأحياء", "علم الفلك", "علم الأحياء الدقيقة"],
        answer: "علم الفلك",
        level: "صعب",
        points: 15
    },

    {
        question: "ما الغاز الأكثر وفرة في الغلاف الجوي للأرض؟",
        options: ["الأكسجين", "النيتروجين", "ثاني أكسيد الكربون", "الهيدروجين"],
        answer: "النيتروجين",
        level: "صعب",
        points: 15
    },

    {
        question: "ما قيمة الجذر التربيعي للعدد 81؟",
        options: ["7", "8", "9", "10"],
        answer: "9",
        level: "صعب",
        points: 15
    },

    {
        question: "ما اسم الطبقة الخارجية الصلبة للأرض؟",
        options: ["اللب الداخلي", "الوشاح", "القشرة الأرضية", "اللب الخارجي"],
        answer: "القشرة الأرضية",
        level: "صعب",
        points: 15
    }
];


// ===============================
// متغيرات اللعبة
// ===============================

let currentIndex = 0;
let score = 0;
let correct = 0;
let wrong = 0;
let timeLeft = 20;
let timer = null;
let answered = false;


// ===============================
// بدء اللعبة
// ===============================

function startGame() {

    currentIndex = 0;
    score = 0;
    correct = 0;
    wrong = 0;

    document.getElementById("startScreen").classList.remove("active");
    document.getElementById("resultScreen").classList.remove("active");
    document.getElementById("gameScreen").classList.add("active");

    document.getElementById("score").textContent = score;

    showQuestion();
}


// ===============================
// عرض السؤال
// ===============================

function showQuestion() {

    clearInterval(timer);

    answered = false;
    timeLeft = 20;

    const current = questions[currentIndex];

    document.getElementById("currentQuestion").textContent =
        currentIndex + 1;

    document.getElementById("questionNumber").textContent =
        currentIndex + 1;

    document.getElementById("question").textContent =
        current.question;

    document.getElementById("timer").textContent =
        timeLeft;

    document.getElementById("score").textContent =
        score;

    const progress =
        ((currentIndex + 1) / questions.length) * 100;

    document.getElementById("progress").style.width =
        progress + "%";


    // مستوى السؤال

    const difficulty =
        document.getElementById("difficulty");

    difficulty.textContent =
        current.level;

    difficulty.className = "difficulty";

    if (current.level === "سهل") {
        difficulty.classList.add("easy");
    }

    if (current.level === "متوسط") {
        difficulty.classList.add("medium");
    }

    if (current.level === "صعب") {
        difficulty.classList.add("hard");
    }


    // الخيارات

    const optionsContainer =
        document.getElementById("options");

    optionsContainer.innerHTML = "";


    // خلط الخيارات

    const shuffledOptions =
        [...current.options].sort(() => Math.random() - 0.5);


    shuffledOptions.forEach(option => {

        const button =
            document.createElement("button");

        button.className = "option";

        button.textContent = option;

        button.onclick = () =>
            selectAnswer(button, option);

        optionsContainer.appendChild(button);
    });


    document.getElementById("feedback").textContent = "";

    document.getElementById("nextBtn").style.display =
        "none";


    startTimer();
}


// ===============================
// المؤقت
// ===============================

function startTimer() {

    const timerElement =
        document.getElementById("timer");

    timerElement.classList.remove("danger");

    timer = setInterval(() => {

        timeLeft--;

        timerElement.textContent =
            timeLeft;


        if (timeLeft <= 5) {
            timerElement.classList.add("danger");
        }


        if (timeLeft <= 0) {

            clearInterval(timer);

            if (!answered) {

                answered = true;

                wrong++;

                showCorrectAnswer();

                document.getElementById("feedback").textContent =
                    "⏰ انتهى الوقت!";

                document.getElementById("feedback").style.color =
                    "#fca5a5";

                document.getElementById("nextBtn").style.display =
                    "inline-block";
            }
        }

    }, 1000);
}


// ===============================
// اختيار الإجابة
// ===============================

function selectAnswer(button, selectedAnswer) {

    if (answered) {
        return;
    }

    answered = true;

    clearInterval(timer);

    const current =
        questions[currentIndex];


    const allOptions =
        document.querySelectorAll(".option");

    allOptions.forEach(option => {
        option.disabled = true;
    });


    if (selectedAnswer === current.answer) {

        button.classList.add("correct");

        correct++;

        score += current.points;

        document.getElementById("score").textContent =
            score;

        document.getElementById("feedback").textContent =
            "✅ إجابة صحيحة! +" + current.points + " نقطة";

        document.getElementById("feedback").style.color =
            "#86efac";

    } else {

        button.classList.add("wrong");

        wrong++;

        showCorrectAnswer();

        document.getElementById("feedback").textContent =
            "❌ إجابة خاطئة!";

        document.getElementById("feedback").style.color =
            "#fca5a5";
    }


    document.getElementById("nextBtn").style.display =
        "inline-block";
}


// ===============================
// إظهار الإجابة الصحيحة
// ===============================

function showCorrectAnswer() {

    const current =
        questions[currentIndex];

    const allOptions =
        document.querySelectorAll(".option");

    allOptions.forEach(option => {

        if (option.textContent === current.answer) {
            option.classList.add("correct");
        }

        option.disabled = true;
    });
}


// ===============================
// السؤال التالي
// ===============================

function nextQuestion() {

    currentIndex++;

    if (currentIndex >= questions.length) {

        endGame();

        return;
    }

    showQuestion();
}


// ===============================
// نهاية اللعبة
// ===============================

function endGame() {

    clearInterval(timer);

    document.getElementById("gameScreen")
        .classList.remove("active");

    document.getElementById("resultScreen")
        .classList.add("active");


    document.getElementById("finalScore")
        .textContent = score;


    document.getElementById("correctAnswers")
        .textContent = correct;


    document.getElementById("wrongAnswers")
        .textContent = wrong;


    const percentage =
        Math.round((correct / questions.length) * 100);

    document.getElementById("percentage")
        .textContent = percentage + "%";


    let message = "";

    if (percentage >= 90) {

        message =
            "🔥 ممتاز جدًا! معلوماتك قوية للغاية!";

    } else if (percentage >= 70) {

        message =
            "👏 أحسنت! نتيجة رائعة.";

    } else if (percentage >= 50) {

        message =
            "👍 جيد! يمكنك تحسين نتيجتك أكثر.";

    } else {

        message =
            "💪 حاول مرة أخرى وتحدى نفسك!";
    }


    document.getElementById("resultMessage")
        .textContent = message;
}


// ===============================
// إعادة اللعبة
// ===============================

function restartGame() {

    document.getElementById("resultScreen")
        .classList.remove("active");

    document.getElementById("startScreen")
        .classList.add("active");

}


// ===============================
// التحقق من عدد الأسئلة
// ===============================

console.log(
    "عدد الأسئلة:",
    questions.length
);

</script>

</body>
</html>
```
